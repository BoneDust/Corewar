/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:49:30 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/24 03:57:26 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void			get_param_types(t_inst **inst)
{
	int			ind;
	int			ind2;
	char		**split;

	ind = 0;
	ind2 = -1;
	while ((*inst)->line[ind] && (*inst)->line[ind] != ' ')
		ind++;
	split = ft_strsplit((*inst)->line + ind, SEPARATOR_CHAR);
	(*inst)->n_params = ft_items_in_grid((void**)split);
	ind = -1;
	while (++ind < (*inst)->n_params)
	{
		(*inst)->params[ind] = ft_strtrim(split[ind]);
		if ((*inst)->params[ind][0] == 'r')
			(*inst)->param_types[++ind2] = T_REG;
		else if ((*inst)->params[ind][0] == DIRECT_CHAR)
			(*inst)->param_types[++ind2] = T_DIR;
		else if (ft_is_number((*inst)->params[ind]) ||
				(*inst)->params[ind][0] == LABEL_CHAR)
			(*inst)->param_types[++ind2] = T_IND;
		else
			(*inst)->param_types[++ind2] = 0;
	}
	ft_destroy_2d((void**)split);
}

static void		fill_params(t_inst **s, t_label *lbls, int i)
{
	while (++i < (*s)->n_params)
	{
		if ((*s)->param_types[i] == T_REG)
		{
			(*s)->param_bytes[i] = 1;
			(*s)->param_v[i] = ft_atoi((*s)->params[i] + 1);
		}
		else if ((*s)->param_types[i] == T_DIR)
		{
			(*s)->param_bytes[i] = (*s)->dir_bytes;
			if (needslabel((*s)->params[i]))
				(*s)->param_v[i] = get_lbl((*s)->params[i], (*s)->index, lbls);
			else
				(*s)->param_v[i] = ft_atoi((*s)->params[i] + 1);
		}
		else if ((*s)->param_types[i] == T_IND)
		{
			(*s)->param_bytes[i] = (*s)->indir_bytes;
			if (needslabel((*s)->params[i]))
				(*s)->param_v[i] = get_lbl((*s)->params[i], (*s)->index, lbls);
			else
				(*s)->param_v[i] = ft_atoi((*s)->params[i]);
		}
	}
}

void			process_params(t_inst **inst, t_label *labels)
{
	get_param_types(inst);
	fill_params(inst, labels, -1);
}
