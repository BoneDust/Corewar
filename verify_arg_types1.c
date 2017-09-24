/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_arg_types1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 23:19:04 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/24 03:31:53 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int		verify_live_fork_lfork_aff_zjmp_arg(t_inst *t)
{
	if (t->opcode == 1 || t->opcode == 9 || t->opcode == 12 || t->opcode == 15)
		return (t->param_types[0] == T_DIR ? 1 : 0);
	else
		return (t->param_types[0] == T_REG ? 1 : 0);
}

int		verify_add_sub_arg(t_inst *t)
{
	int index;

	index = 0;
	while (index < t->n_params)
	{
		if (t->param_types[index] != T_REG)
			return (0);
		index++;
	}
	return (1);
}

int		verify_lld_ld_arg(t_inst *t)
{
	if (t->param_types[0] == T_REG || !t->param_types[0])
		return (0);
	if (t->param_types[1] != T_REG)
		return (0);
	return (1);
}

int		verify_ldi_lldi_arg(t_inst *t)
{
	if (!t->param_types[0])
		return (0);
	if (t->param_types[1] != T_REG && t->param_types[1] != T_DIR)
		return (0);
	if (t->param_types[2] != T_REG)
		return (0);
	return (1);
}

int		verify_and_or_xor(t_inst *t)
{
	if (!t->param_types[0] || !t->param_types[1])
		return (0);
	if (t->param_types[2] != T_REG)
		return (0);
	return (1);
}
