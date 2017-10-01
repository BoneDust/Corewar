/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 19:57:08 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:55:44 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_sub(t_arena **arena, t_champ **champ)
{
	unsigned char	sizes[3];
	int				value[3];
	int				bytes;
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	ft_bzero(sizes, 3);
	decode(5, (*arena)->arena[pc], sizes);
	pc = (pc + 1) % MEM_SIZE;
	value[0] = (*champ)->reg[get_a_value(sizes[0], pc, (*arena)->arena) - 1];
	pc = (pc + sizes[0]) % MEM_SIZE;
	value[1] = (*champ)->reg[get_a_value(sizes[1], pc, (*arena)->arena) - 1];
	pc = (pc + sizes[1]) % MEM_SIZE;
	value[2] = get_a_value(sizes[2], pc, (*arena)->arena);
	(*champ)->reg[value[2] - 1] = value[0] - value[1];
	(*champ)->carry = !(*champ)->carry;
	bytes = 2 + (sizes[0] + sizes[1] + sizes[2]);
	(*champ)->pc += bytes;
}
