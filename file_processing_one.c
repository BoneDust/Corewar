/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:21:58 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/23 03:00:10 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

t_header			init_header(void)
{
	t_header	header;

	header.magic = 0xea83f3;
	ft_bzero(header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(header.comment, COMMENT_LENGTH + 1);
	header.prog_size = 0;
	return (header);
}

void				get_string(char *str, char *line)
{
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	while (line[index] && line[index] != '"')
		index++;
	if (line[index] == '"')
		index++;
	while (line[index] && line[index] != '"')
		str[index2++] = line[index++];
}

t_inst				*create_inst(char *line, int i, int line_nbr)
{
	t_inst	*tmp;

	if (!(tmp = (t_inst*)malloc(sizeof(t_inst))))
		return (NULL);
	if (!(tmp->params = (char**)malloc(sizeof(char*) * (MAX_ARGS_NUMBER))))
		return (NULL);
	tmp->line = ft_strtrim(line);
	tmp->line_nbr = line_nbr;
	tmp->index = 0;
	tmp->bytes = 0;
	tmp->opcode = 0;
	tmp->encoding = 0;
	tmp->hasencoding = 0;
	tmp->n_params = 0;
	tmp->indir_bytes = IND_SIZE;
	tmp->dir_bytes = DIR_SIZE;
	tmp->next = NULL;
	while (++i < MAX_ARGS_NUMBER)
	{
		tmp->params[i] = NULL;
		tmp->param_types[i] = 0;
		tmp->param_v[i] = 0;
		tmp->param_bytes[i] = 0;
	}
	return (tmp);
}

void				add_inst(t_inst **data, t_inst *inst)
{
	t_inst	*iter;

	iter = *data;
	while (iter->next)
		iter = iter->next;
	iter->next = inst;
}
