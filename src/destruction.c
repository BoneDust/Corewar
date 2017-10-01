/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:14:07 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 17:35:06 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	destroy_arena(t_arena **arena)
{
	t_champ	*tmp;
	int		index;

	index = 0;
	tmp = (*arena)->champs;
	if (*arena)
	{
		while (index < MAX_PLAYERS)
		{
			if ((*arena)->p_names[index])
				free((*arena)->p_names[index]);
			index++;
		}
		free((*arena)->p_names);
		while ((*arena)->champs)
		{
			tmp = (*arena)->champs;
			(*arena)->champs = (*arena)->champs->next;
			free(tmp);
			tmp = NULL;
		}
		free(*arena);
		*arena = NULL;
	}
}

t_champ	*destroy_dead_champ(t_arena **arena, int num)
{
	t_champ	*tmp;
	t_champ *tmp2;

	tmp = (*arena)->champs;
	tmp2 = (*arena)->champs;
	while (tmp->player_no != num && tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		if (tmp->player_no == (*arena)->champs->player_no)
		{
			(*arena)->champs = tmp->next;
			free(tmp);
			return ((*arena)->champs);
		}
		tmp2->next = tmp->next;
		free(tmp);
	}
	return (tmp2->next);
}
