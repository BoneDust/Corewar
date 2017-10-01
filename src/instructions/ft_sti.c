/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:16:08 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:55:19 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_sti(t_arena **arena, t_champ **champ)
{
	unsigned char	*val;
	unsigned char	sizes[3];
	int				value[3];
	int				bytes;
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	ft_bzero(sizes, 3);
	decode(11, (*arena)->arena[pc], sizes);
	pc = (pc + 1) % MEM_SIZE;
	value[0] = get_a_value(sizes[0], pc, (*arena)->arena);
	pc = (pc + sizes[0]) % MEM_SIZE;
	value[1] = get_a_value(sizes[1], pc, (*arena)->arena);
	pc = (pc + sizes[1]) % MEM_SIZE;
	value[2] = get_a_value(sizes[2], pc, (*arena)->arena);
	bytes = 2 + (sizes[0] + sizes[1] + sizes[2]);
	pc = ((*champ)->pc + ((value[1] + value[2]) % IDX_MOD)) % MEM_SIZE;
	val = (unsigned char*)&((*champ)->reg[value[0] - 1]);
	to_big_endian(val);
	to_arena(arena, val, pc, REG_SIZE);
	(*champ)->pc += bytes;
}
