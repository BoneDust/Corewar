/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:45:47 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 17:59:33 by nrarane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void		add_champ_to_last(t_arena **arena, t_champ *champ)
{
	t_champ	*tmp;

	tmp = (*arena)->champs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = champ;
}

static int	get_avail(t_arena **arena)
{
	t_champ	*tmp;
	int		max;

	max = 0;
	tmp = (*arena)->champs;
	while (tmp)
	{
		if (tmp->player_no > max)
			max = tmp->player_no;
		tmp = tmp->next;
	}
	return (max + 1);
}

t_champ		*create_fork_champ(t_champ *champ, t_arena **arena, int ind)
{
	t_champ	*nchamp;
	int		index;

	if (!(nchamp = (t_champ*)malloc(sizeof(t_champ))))
		return (NULL);
	index = 0;
	while (index < REG_NUMBER)
	{
		nchamp->reg[index] = champ->reg[index];
		index++;
	}
	nchamp->player_no = get_avail(arena);
	nchamp->alive = champ->alive;
	nchamp->wait = champ->wait;
	nchamp->run = champ->run;
	nchamp->carry = champ->carry;
	nchamp->player_size = champ->player_size;
	ft_memcpy(nchamp->name, champ->name, PROG_NAME_LENGTH + 1);
	ft_memcpy(nchamp->comment, champ->comment, COMMENT_LENGTH + 1);
	ft_bzero((void*)nchamp->prog, CHAMP_MAX_SIZE);
	ft_memcpy(nchamp->prog, champ->prog, champ->player_size);
	nchamp->pc = champ->pc + ind;
	nchamp->next = NULL;
	return (nchamp);
}

void		ft_fork(t_arena **arena, t_champ **champ)
{
	int				value[3];
	int				pc;
	t_champ			*new_champ;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	value[0] = get_a_value(IND_SIZE, pc, (*arena)->arena);
	new_champ = create_fork_champ(*champ, arena, value[0] % IDX_MOD);
	add_champ_to_last(arena, new_champ);
	(*champ)->pc += IND_SIZE + 1;
	to_arena(arena, new_champ->prog, new_champ->pc, new_champ->player_size);
}
