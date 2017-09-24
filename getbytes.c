/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getbytes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:53:49 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/23 04:25:52 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

int			get_bytes_in_line(const char *line, int bytes)
{
	int				index;
	char			*trimmed;
	char			**sp;
	char			**sp2;
	unsigned char	op;

	index = -1;
	sp = ft_strsplit(line, ' ');
	op = ft_get_opcode(sp[0]);
	sp2 = ft_strsplit(line + ft_strlen(sp[0]), SEPARATOR_CHAR);
	bytes = (op == 1 ? 5 : 1);
	if (!(op == 1 || op == 9 || op == 12 || op == 15))
		bytes++;
	while (op != 1 && sp2[++index])
	{
		trimmed = ft_strtrim(sp2[index]);
		if (trimmed[0] == DIRECT_CHAR)
			bytes += (op < 9 || op == 13 || op == 16 ? DIR_SIZE : IND_SIZE);
		else
			bytes += (trimmed[0] == 'r' ? 1 : IND_SIZE);
		free(trimmed);
	}
	ft_destroy_2d((void**)sp);
	ft_destroy_2d((void**)sp2);
	return (bytes);
}

int			get_number_of_params(unsigned char op)
{
	if (op == 1 || op == 9 || op == 12 || op == 15 || op == 16)
		return (1);
	else if (op == 2 || op == 3 || op == 13)
		return (2);
	else
		return (3);
}
