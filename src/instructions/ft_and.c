/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:11:59 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:41:51 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_and(t_arena **arena, t_champ **champ)
{
	unsigned char	sizes[3];
	int				values[3];
	int				bytes;
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	ft_bzero(sizes, 3);
	decode(6, (*arena)->arena[pc], sizes);
	pc = (pc + 1) % MEM_SIZE;
	values[0] = get_a_value(sizes[0], pc, (*arena)->arena);
	pc = (pc + sizes[0]) % MEM_SIZE;
	values[1] = get_a_value(sizes[1], pc, (*arena)->arena);
	pc = (pc + sizes[1]) % MEM_SIZE;
	values[2] = get_a_value(sizes[2], pc, (*arena)->arena);
	if (sizes[0] == 1)
		values[0] = (*champ)->reg[values[0] - 1];
	if (sizes[1] == 1)
		values[1] = (*champ)->reg[values[1] - 1];
	(*champ)->reg[values[2] - 1] = values[0] & values[1];
	(*champ)->carry = !(*champ)->carry;
	bytes = 2 + (sizes[0] + sizes[1] + sizes[2]);
	(*champ)->pc += bytes;
}
