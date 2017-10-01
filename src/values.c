/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:41:20 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:40:21 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int		get_a_value(int size, int pc, unsigned char *arena)
{
	unsigned char	num_in_bytes[4];
	int				num;

	ft_bzero(num_in_bytes, 4);
	arena_val(arena, size, pc, num_in_bytes);
	num = bytes_to_int(num_in_bytes, size);
	return (num);
}

void	to_big_endian(unsigned char *num)
{
	unsigned char temp[4];

	temp[0] = num[3];
	temp[1] = num[2];
	temp[2] = num[1];
	temp[3] = num[0];
	num[0] = temp[0];
	num[1] = temp[1];
	num[2] = temp[2];
	num[3] = temp[3];
}

void	to_arena(t_arena **arena, unsigned char *bytes, int pc, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (pc > (MEM_SIZE - 1))
			pc = 0;
		(*arena)->arena[pc++] = bytes[index++];
	}
}

void	arena_val(unsigned char *arena, int s, int pc, unsigned char *buf)
{
	int index;

	index = 0;
	while (index < s)
	{
		if (pc > (MEM_SIZE - 1))
			pc = 0;
		buf[index++] = arena[pc++];
	}
}
