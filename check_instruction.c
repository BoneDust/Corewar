/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 23:06:39 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/24 04:23:44 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static void		check_param_types(t_inst *t, t_inst **data, t_label **label)
{
	get_param_types(&t);
	if (t->opcode == 1 || t->opcode == 9 || t->opcode == 12 ||
			t->opcode == 15 || t->opcode == 16)
	{
		if (!verify_live_fork_lfork_aff_zjmp_arg(t))
			print_inst_err("Invalid argument type found.", data, label, t);
	}
	if ((t->opcode == 4 || t->opcode == 5) && !verify_add_sub_arg(t))
		print_inst_err("Invalid argument type found.", data, label, t);
	if ((t->opcode == 2 || t->opcode == 13) && !verify_lld_ld_arg(t))
		print_inst_err("Invalid argument type found.", data, label, t);
	if ((t->opcode == 10 || t->opcode == 14) && !verify_ldi_lldi_arg(t))
		print_inst_err("Invalid argument type found.", data, label, t);
	if (t->opcode >= 6 && t->opcode <= 8 && !verify_and_or_xor(t))
		print_inst_err("Invalid argument type found.", data, label, t);
	if (t->opcode == 3 && !verify_st_arg(t))
		print_inst_err("Invalid argument type found.", data, label, t);
	if (t->opcode == 11 && !verify_sti_arg(t))
		print_inst_err("Invalid argument type found.", data, label, t);
}

static void		check_param_values(t_inst *t, t_inst **data, t_label **label)
{
	int i;

	i = -1;
	while (++i < t->n_params)
	{
		if (t->param_types[i] == T_REG)
			verify_reg_value(t, data, label, i);
		else if (t->param_types[i] == T_IND)
			verify_ind_value(t, data, label, i);
		else if (t->param_types[i] == T_DIR)
			verify_dir_value(t, data, label, i);
	}
}

static void		validate_line(t_inst *inst, t_inst **data, t_label **label)
{
	char			**split;
	char			*opcode;
	unsigned char	op;

	split = ft_strsplit(inst->line, ' ');
	opcode = split[0];
	if (!(op = ft_get_opcode(opcode)))
	{
		ft_destroy_2d((void**)split);
		print_inst_err("Invalid instruction found", data, label, inst);
	}
	ft_destroy_2d((void**)split);
	if (get_number_of_params(op) != count(inst->line, SEPARATOR_CHAR) + 1)
		print_inst_err("Incorrect number of arguments", data, label, inst);
	inst->opcode = op;
	inst->n_params = get_number_of_params(op);
	check_param_types(inst, data, label);
	check_param_values(inst, data, label);
}

void			check_instructions(int line_nbr, int fd)
{
	t_label	*labels;
	t_inst	*iter;
	t_inst	*data;

	data = NULL;
	labels = NULL;
	get_file(fd, line_nbr, &data, NULL);
	get_n_check_labels(&data, &labels);
	iter = data;
	while (iter)
	{
		if (iter->line && ft_strlen(iter->line) > 0)
			validate_line(iter, &data, &labels);
		iter = iter->next;
	}
	destroy_labels(labels);
	destroy_data(data);
}
