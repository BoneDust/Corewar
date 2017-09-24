/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 23:05:45 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/24 04:21:19 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

void	print_err(char *msg, char **line, int line_nbr, int col)
{
	ft_putchar('\n');
	if (line_nbr != -1 || col != -1)
	{
		ft_putstr("Error : line ");
		ft_putnbr(line_nbr);
		if (col >= 0)
		{
			ft_putstr(", col ");
			ft_putnbr(col + 1);
		}
		ft_putstr(". ");
		ft_putendl(msg);
	}
	else
		ft_putendl(msg);
	ft_strdel(line);
	exit(0);
}

void	error_analysis(char *file, int line_nbr, int found_name_com, int fd)
{
	char	*line;
	char	*tmp;

	line = NULL;
	if (!(file[ft_strlen(file) - 1] == 's' && file[ft_strlen(file) - 2] == '.'))
		print_err("Invalid file  : file is not a .s file", &line, -1, -1);
	if ((fd = open(file, O_RDONLY)) == -1)
		print_err("Error : file not found", &line, -1, -1);
	while (get_next_line(fd, &line) > 0 && ++line_nbr)
	{
		ft_replace(&line, '\t', ' ');
		tmp = ft_strtrim(line);
		if (tmp[0] == COMMENT_CHAR || ft_strlen(tmp) == 0)
			continue ;
		if (found_name_com != 2)
			check_header(&line, line_nbr, &found_name_com);
		if (found_name_com == 2)
			check_instructions(line_nbr, fd);
		free(tmp);
	}
	free(line);
	ft_putstr("\nFile << ");
	ft_putstr(file);
	ft_putendl(" >> successfully compiled.");
	close(fd);
}
