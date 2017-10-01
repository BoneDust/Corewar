/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 11:36:16 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:56:04 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_lldi(t_arena **arena, t_champ **champ)
{
	unsigned char	size[3];
	int				val[3];
	unsigned char	s_bytes[REG_SIZE];
	int				new_pc;
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	ft_bzero(size, 3);
	decode(14, (*arena)->arena[pc], size);
	pc = (pc + 1) % MEM_SIZE;
	val[0] = get_a_value(size[0], pc, (*arena)->arena);
	pc = (pc + size[0]) % MEM_SIZE;
	val[1] = get_a_value(size[1], pc, (*arena)->arena);
	pc = (pc + size[1]) % MEM_SIZE;
	val[2] = get_a_value(size[2], pc, (*arena)->arena);
	pc = (pc + size[2]) % MEM_SIZE;
	if (size[0] == 1)
		val[0] = (*champ)->reg[val[0] - 1];
	if (size[1] == 1)
		val[1] = (*champ)->reg[val[1] - 1];
	new_pc = (*champ)->pc + (val[0] + val[1]);
	arena_val((*arena)->arena, REG_SIZE, new_pc, s_bytes);
	(*champ)->pc = 2 + (size[0] + size[1] + size[2]);
	(*champ)->reg[val[2] - 1] = bytes_to_int(s_bytes, REG_SIZE);
	(*champ)->carry = !(*champ)->carry;
}
