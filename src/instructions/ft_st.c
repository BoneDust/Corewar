/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 20:13:53 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 15:14:51 by nrarane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_st(t_arena **arena, t_champ **champ)
{
	unsigned char	*val;
	unsigned char	sizes[3];
	int				value[3];
	int				new_pc;
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	ft_bzero(sizes, 3);
	decode(3, (*arena)->arena[pc], sizes);
	pc = (pc + 1) % MEM_SIZE;
	value[0] = (*champ)->reg[get_a_value(sizes[0], pc, (*arena)->arena) - 1];
	pc = (pc + sizes[0]) % MEM_SIZE;
	value[1] = get_a_value(sizes[1], pc, (*arena)->arena);
	if (sizes[1] == 1)
		(*champ)->reg[value[1] - 1] = value[0];
	else
	{
		val = (unsigned char*)&value[0];
		to_big_endian(val);
		new_pc = (*champ)->pc + (value[1] % IDX_MOD);
		to_arena(arena, val, new_pc, REG_SIZE);
	}
	(*champ)->pc += 2 + sizes[0] + sizes[1];
}
