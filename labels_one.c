/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:04:53 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/23 04:39:01 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int			is_label_only(char *line)
{
	char	**split;

	if (ft_strchr(line, LABEL_CHAR))
	{
		split = ft_strsplit(line, LABEL_CHAR);
		if (ft_items_in_grid((void **)split) == 1)
		{
			ft_destroy_2d((void **)split);
			return (1);
		}
		else
		{
			ft_destroy_2d((void **)split);
			return (0);
		}
	}
	else
		return (0);
}

int			contains_label(char *line)
{
	char **split;

	split = ft_strsplit(line, ' ');
	if (ft_strchr(split[0], LABEL_CHAR))
	{
		ft_destroy_2d((void **)split);
		return (1);
	}
	ft_destroy_2d((void **)split);
	return (0);
}

t_label		*create_label(char **line, int total_bytes)
{
	t_label		*label;
	char		**split;
	char		*tmp;
	int			lbl_len;

	if (!(label = (t_label*)malloc(sizeof(t_label))))
		return (NULL);
	split = ft_strsplit(*line, LABEL_CHAR);
	label->name = ft_strdup(split[0]);
	label->index = total_bytes + 1;
	label->next = NULL;
	lbl_len = ft_strlen(label->name);
	tmp = ft_strdup(*line);
	free(*line);
	*line = ft_strsub(tmp, lbl_len + 1, ft_strlen(tmp) - lbl_len - 1);
	free(tmp);
	tmp = ft_strtrim(*line);
	free(*line);
	*line = tmp;
	ft_destroy_2d((void **)split);
	return (label);
}

void		add_label(t_label **label, t_label *new_label)
{
	new_label->next = *label;
	*label = new_label;
}

int			found_label(t_label *label, char *name)
{
	t_label	*tmp;

	tmp = label;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
