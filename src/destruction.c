/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:14:07 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 11:13:00 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	destroy_arena(t_arena **arena)
{
	t_champ	*tmp;

	if (*arena)
	{
		ft_destroy_2d((void**)(*arena)->p_names);
		while ((*arena)->champs)
		{
			tmp = (*arena)->champs;
			(*arena)->champs = (*arena)->champs->next;
			free(tmp);
		}
		free(*arena);
		*arena = NULL;
	}
}
