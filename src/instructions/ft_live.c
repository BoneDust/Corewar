/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 21:49:10 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 16:08:33 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_live(t_arena **are, t_champ **chp)
{
	int				value[3];
	int				bytes;
	int				pc;

	pc = ((*chp)->pc + 1) % MEM_SIZE;
	value[0] = get_a_value(REG_SIZE, pc, (*are)->arena);
	bytes = 5;
	(*chp)->pc += bytes;
	if (value[0] == (*chp)->player_no)
	{
		(*chp)->alive++;
		(*are)->last_live = value[0];
		ft_memcpy((*are)->winner, (*chp)->name, PROG_NAME_LENGTH + 1);
		ft_memcpy((*are)->winner_comment, (*chp)->comment, COMMENT_LENGTH + 1);
		ft_putstr("A process shows that player ");
		ft_putnbr(value[0]);
		ft_putstr(" (");
		ft_putstr((*chp)->name);
		ft_putstr(") is alive\n");
	}
}
