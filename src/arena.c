/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:32:40 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 11:01:18 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	dump_memory(t_arena **arena)
{
	int i;

	i = -1;
	ft_putchar('\n');
	while (++i < MEM_SIZE)
	{
		if (!(i % 32) && i > 0)
			ft_putchar('\n');
		else if (i > 0)
			ft_putchar(' ');
		if ((*arena)->arena[i] < 16)
			ft_putchar('0');
		ft_printhex((*arena)->arena[i]);
	}
	ft_putchar('\n');
	exit_prog("", arena);
}

void	load_arena(t_arena **arena)
{
	int		i;
	int		players;
	int		p_field_size;
	t_champ	*champ;
	int		start_pos;

	p_field_size = MEM_SIZE / (*arena)->players;
	i = 0;
	while (++i <= (*arena)->players)
	{
		champ = (*arena)->champs;
		players = (*arena)->players;
		start_pos = p_field_size * (i - 1);
		while (players-- > i)
			champ = champ->next;
		ft_memcpy((void*)(*arena)->arena + start_pos,
				(const void*)champ->prog, champ->player_size);
		champ->pc = start_pos;
	}
}
