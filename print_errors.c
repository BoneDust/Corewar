/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 23:13:18 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/24 03:38:18 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	print_inst_err(char *msg, t_inst **data, t_label **labels, t_inst *inst)
{
	ft_putchar('\n');
	ft_putstr("Error found in line ");
	ft_putnbr(inst->line_nbr + 1);
	ft_putstr(": ");
	ft_putendl(msg);
	destroy_labels(*labels);
	destroy_data(*data);
	exit(0);
}

void	print_reg_err(t_inst *t, t_inst **data, t_label **label, int col)
{
	ft_putchar('\n');
	ft_putstr("Error found in line ");
	ft_putnbr(t->line_nbr + 1);
	ft_putstr(", argument ");
	ft_putnbr(col);
	ft_putstr(": ");
	ft_putendl("Invalid reg value.");
	destroy_labels(*label);
	destroy_data(*data);
	exit(0);
}

void	print_ind_err(t_inst *t, t_inst **data, t_label **label, int col)
{
	ft_putchar('\n');
	ft_putstr("Error found in line ");
	ft_putnbr(t->line_nbr + 1);
	ft_putstr(", argument ");
	ft_putnbr(col);
	ft_putstr(": ");
	ft_putendl("Invalid indirect value.");
	destroy_labels(*label);
	destroy_data(*data);
	exit(0);
}

void	print_dir_err(t_inst *t, t_inst **data, t_label **label, int col)
{
	ft_putchar('\n');
	ft_putstr("Error found in line ");
	ft_putnbr(t->line_nbr + 1);
	ft_putstr(", argument ");
	ft_putnbr(col);
	ft_putstr(": ");
	ft_putendl("Invalid direct value.");
	destroy_labels(*label);
	destroy_data(*data);
	exit(0);
}

void	print_lbl_err(t_inst *t, t_inst **data, t_label **label, int col)
{
	ft_putchar('\n');
	ft_putstr("Error found in line ");
	ft_putnbr(t->line_nbr + 1);
	ft_putstr(", argument ");
	ft_putnbr(col);
	ft_putstr(": ");
	ft_putendl("Non-existing label.");
	destroy_labels(*label);
	destroy_data(*data);
	exit(0);
}
