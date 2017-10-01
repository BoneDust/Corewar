/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 20:12:42 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:44:35 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_xor(t_arena **arena, t_champ **champ)
{
	unsigned char	sizes[3];
	int				value[3];
	int				bytes;
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	ft_bzero(sizes, 3);
	decode(8, (*arena)->arena[pc], sizes);
	pc = (pc + 1) % MEM_SIZE;
	value[0] = get_a_value(sizes[0], pc, (*arena)->arena);
	pc = (pc + sizes[0]) % MEM_SIZE;
	value[1] = get_a_value(sizes[1], pc, (*arena)->arena);
	pc = (pc + sizes[1]) % MEM_SIZE;
	value[2] = get_a_value(sizes[2], pc, (*arena)->arena);
	if (sizes[0] == 1)
		value[0] = (*champ)->reg[value[0] - 1];
	if (sizes[1] == 1)
		value[1] = (*champ)->reg[value[1] - 1];
	(*champ)->reg[value[2] - 1] = value[0] ^ value[1];
	(*champ)->carry = !(*champ)->carry;
	bytes = 2 + (sizes[0] + sizes[1] + sizes[2]);
	(*champ)->pc += bytes;
}
