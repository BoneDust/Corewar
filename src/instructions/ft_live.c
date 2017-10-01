/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 21:49:10 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:32:06 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_live(t_arena **arena, t_champ **champ)
{
	int				value[3];
	int				bytes;
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	value[0] = get_a_value(REG_SIZE, pc, (*arena)->arena);
	bytes = 5;
	(*champ)->pc += bytes;
	if (value[0] == (*champ)->player_no)
	{
		(*champ)->alive++;
		(*arena)->last_live = value[0];
		ft_putstr("A process shows that player ");
		ft_putnbr(value[0]);
		ft_putstr(" (");
		ft_putstr((*champ)->name);
		ft_putstr(") is alive\n");
	}
}
