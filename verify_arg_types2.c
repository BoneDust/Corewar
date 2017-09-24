/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_arg_types2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:25:58 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/24 03:22:22 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int			verify_st_arg(t_inst *t)
{
	if (t->param_types[0] != T_REG)
		return (0);
	if (t->param_types[1] != T_REG && t->param_types[1] != T_IND)
		return (0);
	return (1);
}

int			verify_sti_arg(t_inst *t)
{
	if (t->param_types[0] != T_REG || !t->param_types[1])
		return (0);
	if (t->param_types[2] != T_DIR && t->param_types[2] != T_REG)
		return (0);
	return (1);
}
