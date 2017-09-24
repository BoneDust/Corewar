/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 01:39:12 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/24 03:46:15 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	verify_reg_value(t_inst *t, t_inst **data, t_label **label, int ind)
{
	int	num;

	if (!ft_is_number(t->params[ind] + 1))
		print_reg_err(t, data, label, ind + 1);
	if (ft_out_of_int_range(t->params[ind] + 1))
		print_reg_err(t, data, label, ind + 1);
	num = ft_atoi(t->params[ind] + 1);
	if (!(num >= 1 && num <= REG_NUMBER))
		print_reg_err(t, data, label, ind + 1);
}

void	verify_ind_value(t_inst *t, t_inst **data, t_label **label, int ind)
{
	if (ft_is_number(t->params[ind]))
	{
		if (ft_out_of_int_range(t->params[ind]))
			print_ind_err(t, data, label, ind + 1);
	}
	else if (!found_label(*label, t->params[ind] + 1))
		print_lbl_err(t, data, label, ind + 1);
}

void	verify_dir_value(t_inst *t, t_inst **data, t_label **label, int ind)
{
	if (ft_is_number(t->params[ind] + 1))
	{
		if (ft_out_of_int_range(t->params[ind] + 1))
			print_dir_err(t, data, label, ind + 1);
	}
	else if (!found_label(*label, t->params[ind] + 2))
		print_lbl_err(t, data, label, ind + 1);
}
