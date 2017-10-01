/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 20:38:08 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:54:07 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_aff(t_arena **arena, t_champ **champ)
{
	int				value[3];
	int				bytes;
	int				pc;

	pc = ((*champ)->pc + 2) % MEM_SIZE;
	value[0] = (*champ)->reg[get_a_value(1, pc, (*arena)->arena) - 1];
	bytes = 3;
	ft_putchar(value[0] % 256);
	(*champ)->pc += bytes;
}
