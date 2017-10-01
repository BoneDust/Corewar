/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 12:29:11 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 13:53:13 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_lfork(t_arena **arena, t_champ **champ)
{
	int				value[3];
	int				pc;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	value[0] = get_a_value(IND_SIZE, pc, (*arena)->arena);
	create_fork_champ(*champ, arena, value[0]);
	(*champ)->pc += IND_SIZE + 1;
}
