/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamashil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:34:27 by pamashil          #+#    #+#             */
/*   Updated: 2017/09/22 20:55:32 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

unsigned	char		bintodec(char *bin_no)
{
	unsigned	char	nbr;
	int					byte;

	byte = 128;
	nbr = 0;
	while (byte)
	{
		if (*bin_no == '1')
			nbr += byte;
		bin_no++;
		byte /= 2;
	}
	return (nbr);
}

static void				write_numbers(unsigned char *line, int bytes, int fd)
{
	int	i;

	i = bytes;
	while (i--)
		write(fd, &line[i], 1);
}

static void				write_binary(unsigned char *line, int bytes, int fd)
{
	write(fd, line, bytes);
}

static void				write_inst(t_inst *inst, int fd)
{
	int				i;
	unsigned char	*temp;

	i = -1;
	write(fd, &inst->opcode, 1);
	if (inst->hasencoding)
		write(fd, &inst->encoding, 1);
	while (++i < inst->n_params)
	{
		temp = (unsigned char*)&inst->param_v[i];
		write_numbers(temp, inst->param_bytes[i], fd);
	}
}

void					write_to_cor(t_inst *inst, t_header header, int fd)
{
	unsigned char	*line;
	unsigned char	byte[4];
	t_inst			*iter;

	ft_bzero(byte, 4);
	line = (unsigned char*)(&header.magic);
	write_numbers(line, sizeof(unsigned int), fd);
	line = (unsigned char*)header.prog_name;
	write_binary(line, PROG_NAME_LENGTH, fd);
	write_binary(byte, 4, fd);
	line = (unsigned char*)(&header.prog_size);
	write_numbers(line, sizeof(unsigned int), fd);
	line = (unsigned char*)header.comment;
	write_binary(line, COMMENT_LENGTH, fd);
	write_binary(byte, 4, fd);
	iter = inst;
	while (iter != NULL)
	{
		if (ft_strlen(iter->line) > 0)
			write_inst(iter, fd);
		iter = iter->next;
	}
}
