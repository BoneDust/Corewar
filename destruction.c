/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:43:08 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/08 11:43:42 by nrarane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void		destroy_labels(t_label *labels)
{
	t_label	*tmp;

	while (labels)
	{
		tmp = labels;
		labels = labels->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp);
		tmp = NULL;
	}
}

void		destroy_data(t_inst *data)
{
	t_inst	*tmp;

	while (data)
	{
		tmp = data;
		data = data->next;
		ft_destroy_2d((void**)tmp->params);
		free(tmp->line);
		tmp->line = NULL;
		free(tmp);
		tmp = NULL;
	}
}
