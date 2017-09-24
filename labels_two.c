/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:05:23 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/24 04:10:22 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int			needslabel(char *param)
{
	if (ft_strchr(param, LABEL_CHAR))
		return (1);
	return (0);
}

int			get_lbl(char *item, int index, t_label *labels)
{
	char	**split;
	int		num;
	t_label	*tmp;

	tmp = labels;
	split = ft_strsplit(item, LABEL_CHAR);
	num = ft_items_in_grid((void**)split);
	while (tmp)
	{
		if ((ft_strequ(tmp->name, split[num == 1 ? 0 : 1])))
		{
			ft_destroy_2d((void**)split);
			return (tmp->index - index);
		}
		tmp = tmp->next;
	}
	ft_destroy_2d((void**)split);
	return (index);
}

void		create_all_lbls(t_label **labels, t_inst **data, int total_bytes)
{
	t_inst	*ins;

	ins = *data;
	while (ins)
	{
		if (is_label_only(ins->line) || contains_label(ins->line))
		{
			if (*labels == NULL)
				*labels = create_label(&ins->line, total_bytes);
			else
				add_label(labels, create_label(&ins->line, total_bytes));
		}
		if (ins->line && ft_strlen(ins->line) > 0)
			total_bytes += get_bytes_in_line(ins->line, 0);
		ins = ins->next;
	}
}

int			label_chars_valid(char *line)
{
	char	**split;
	char	*label_name;
	int		index;

	index = 0;
	split = ft_strsplit(line, LABEL_CHAR);
	label_name = split[0];
	while (label_name[index])
	{
		if (!ft_contains(LABEL_CHARS, label_name[index]))
		{
			ft_destroy_2d((void**)split);
			return (0);
		}
		index++;
	}
	ft_destroy_2d((void**)split);
	return (1);
}

void		get_n_check_labels(t_inst **data, t_label **lbl)
{
	t_inst	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (is_label_only(tmp->line) || contains_label(tmp->line))
		{
			if (*lbl == NULL)
			{
				if (label_chars_valid(tmp->line))
					*lbl = create_label(&tmp->line, 0);
				else
					print_inst_err("Label has invalid chars.", data, lbl, tmp);
			}
			else
			{
				if (label_chars_valid(tmp->line))
					add_label(lbl, create_label(&tmp->line, 0));
				else
					print_inst_err("Label has invalid chars.", data, lbl, tmp);
			}
		}
		tmp = tmp->next;
	}
}
