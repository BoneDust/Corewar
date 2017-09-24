/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:23:54 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/24 03:48:37 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void				cut_off_comment(char **line)
{
	char	**split;

	if (ft_strchr(*line, COMMENT_CHAR))
	{
		split = ft_strsplit(*line, COMMENT_CHAR);
		free(*line);
		*line = ft_strdup(split[0]);
		ft_destroy_2d((void**)split);
	}
}

void				get_file(int fd, int line_nbr, t_inst **lst, t_header *head)
{
	char	*line;
	char	**split;

	line = NULL;
	while (get_next_line(fd, &line) > 0 && line_nbr++)
	{
		ft_replace(&line, '\t', ' ');
		split = ft_strsplit(line, ' ');
		if (split[0] && !ft_strcmp(split[0], NAME_CMD_STRING))
			get_string(head->prog_name, line);
		else if (split[0] && !ft_strcmp(split[0], COMMENT_CMD_STRING))
			get_string(head->comment, line);
		else if (split[0] && split[0][0] != COMMENT_CHAR)
		{
			cut_off_comment(&line);
			if (*lst == NULL)
				*lst = create_inst(line, -1, line_nbr - 1);
			else
				add_inst(lst, create_inst(line, -1, line_nbr - 1));
		}
		ft_destroy_2d((void**)split);
	}
	free(line);
}

static void			update_inst(t_inst **ins, int total_bytes, t_label *labels)
{
	char			**split;
	unsigned char	op;

	split = ft_strsplit((*ins)->line, ' ');
	op = ft_get_opcode(split[0]);
	(*ins)->opcode = op;
	(*ins)->hasencoding = (op == 1 || op == 9 || op == 12 || op == 15 ? 0 : 1);
	(*ins)->bytes = get_bytes_in_line((*ins)->line, 0);
	(*ins)->index = total_bytes + 1;
	(*ins)->dir_bytes = (op < 9 || op == 13 || op == 16 ? DIR_SIZE : IND_SIZE);
	process_params(ins, labels);
	(*ins)->encoding = ft_get_encoding((*ins)->param_types, (*ins)->n_params);
	ft_destroy_2d((void**)split);
}

void				encode_to_file(int w_fd, int r_fd, int total_bytes)
{
	t_inst		*data;
	t_inst		*iter;
	t_label		*labels;
	t_header	header;

	data = NULL;
	labels = NULL;
	header = init_header();
	get_file(r_fd, 1, &data, &header);
	create_all_lbls(&labels, &data, total_bytes);
	iter = data;
	while (iter)
	{
		if (iter->line && ft_strlen(iter->line) > 0)
		{
			update_inst(&iter, total_bytes, labels);
			total_bytes += iter->bytes;
		}
		iter = iter->next;
	}
	header.prog_size = total_bytes;
	write_to_cor(data, header, w_fd);
	destroy_labels(labels);
	destroy_data(data);
}
