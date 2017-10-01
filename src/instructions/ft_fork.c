/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:45:47 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:53:38 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	create_fork_champ(t_champ *champ, t_arena **arena, int ind)
{
	t_champ	*nchamp;
	int		index;

	if (!(nchamp = (t_champ*)malloc(sizeof(t_champ))))
		exit_prog("\nError : Mem allocation faled for a forked champ.", arena);
	index = 0;
	while (index < REG_NUMBER)
	{
		nchamp->reg[index] = champ->reg[index];
		index++;
	}
	nchamp->player_no = champ->player_no;
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
	add_to_champs(&(*arena)->champs, nchamp);
	to_arena(arena, nchamp->prog, nchamp->pc, champ->player_size);
}

void	ft_fork(t_arena **arena, t_champ **champ)
{
	int				value[3];
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	value[0] = get_a_value(IND_SIZE, pc, (*arena)->arena);
	create_fork_champ(*champ, arena, value[0] % IDX_MOD);
	(*champ)->pc += IND_SIZE + 1;
}
