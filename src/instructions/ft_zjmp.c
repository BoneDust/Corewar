/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 21:56:15 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:45:40 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_zjmp(t_arena **arena, t_champ **champ)
{
	int				value[3];
	int				pc;

	pc = ((*champ)->pc) % MEM_SIZE;
	if (!(*champ)->carry)
		(*champ)->pc++;
	else
	{
		value[0] = get_a_value(IND_SIZE, pc + 1, (*arena)->arena);
		(*champ)->pc += (value[0] % IDX_MOD);
	}
}
