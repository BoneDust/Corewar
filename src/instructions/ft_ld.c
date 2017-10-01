/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 22:19:44 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:40:04 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_ld(t_arena **arena, t_champ **champ)
{
	unsigned char	size[3];
	int				value[3];
	int				n_pc;
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	ft_bzero(size, 3);
	decode(2, (*arena)->arena[pc], size);
	pc = (pc + 1) % MEM_SIZE;
	value[0] = get_a_value(size[0], pc, (*arena)->arena);
	n_pc = (*champ)->pc + (value[0] % IDX_MOD);
	pc = (pc + size[0]) % MEM_SIZE;
	value[1] = get_a_value(size[1], pc, (*arena)->arena);
	(*champ)->reg[value[1] - 1] = get_a_value(REG_SIZE, n_pc, (*arena)->arena);
	(*champ)->pc += 2 + size[0] + size[1];
	(*champ)->carry = !(*champ)->carry;
}
