/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 12:29:11 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 17:59:55 by nrarane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../vm.h"

void	ft_lfork(t_arena **arena, t_champ **champ)
{
	int				value[3];
	int				pc;
	t_champ			*new_champ;

	pc = ((*champ)->pc + 1) % MEM_SIZE;
	value[0] = get_a_value(IND_SIZE, pc, (*arena)->arena);
	new_champ = create_fork_champ(*champ, arena, value[0]);
	add_champ_to_last(arena, new_champ);
	(*champ)->pc += IND_SIZE + 1;
	to_arena(arena, new_champ->prog, new_champ->pc, new_champ->player_size);
}
