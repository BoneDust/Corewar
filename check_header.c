/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 23:07:54 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/23 23:08:02 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static int		found_name(char **line, int line_nbr, int ind, int len)
{
	while (*line[ind] == ' ')
		ind++;
	if (ft_strstr(*line, NAME_CMD_STRING) - *line - ind == 0)
	{
		ind = ft_strstr(*line, NAME_CMD_STRING) - *line;
		ind += ft_strlen(NAME_CMD_STRING);
		while ((*line)[ind] && (*line)[ind] != '"' && (*line)[ind] == ' ')
			ind++;
		if ((*line)[ind] != '"' && (*line)[ind] != '\0')
			print_err("Invalid  character found.", line, line_nbr, ind);
		if ((*line)[ind] == '\0')
			print_err("Error found : Program name not found", line, -1, -1);
		ind++;
		while ((*line)[ind] && (*line)[ind] != '"' && ++len)
			ind++;
		if ((*line)[ind++] == '\0')
			print_err("Error found : Program name not found", line, -1, -1);
		while ((*line)[ind] && (*line)[ind] == ' ')
			ind++;
		if ((*line)[ind] != '\0')
			print_err("Invalid character found.", line, line_nbr, ind);
		return (len);
	}
	else
		return (-1);
}

static int		found_comment(char **line, int line_nbr, int ind, int len)
{
	while ((*line)[ind] == ' ')
		ind++;
	if (ft_strstr(*line, COMMENT_CMD_STRING) - *line - ind == 0)
	{
		ind = ft_strstr(*line, COMMENT_CMD_STRING) - *line;
		ind += ft_strlen(COMMENT_CMD_STRING);
		while ((*line)[ind] && (*line)[ind] != '"' && (*line)[ind] == ' ')
			ind++;
		if ((*line)[ind] != '"' && (*line)[ind] != '\0')
			print_err("Invalid character found.", line, line_nbr, ind);
		if ((*line)[ind] == '\0')
			print_err("Error : Program comment not found", line, -1, -1);
		ind++;
		while ((*line)[ind] && (*line)[ind] != '"' && ++len)
			ind++;
		if ((*line)[ind++] == '\0')
			print_err("Error : Program comment not found", line, -1, -1);
		while ((*line)[ind] && (*line)[ind] == ' ')
			ind++;
		if ((*line)[ind] != '\0')
			print_err("Invalid character found.", line, line_nbr, ind);
		return (len);
	}
	else
		return (-1);
}

void			check_header(char **line, int line_nbr, int *found_name_com)
{
	int index;
	int len;

	len = 0;
	index = 0;
	if (!*found_name_com)
	{
		if ((len = found_name(line, line_nbr, index, len)) == -1)
			print_err("Error : NAME_CMD_STRING not found", line, -1, -1);
		else if (len > PROG_NAME_LENGTH)
			print_err("Error : name length exceeds limit", line, -1, -1);
		*found_name_com = 1;
	}
	else if (*found_name_com == 1)
	{
		if ((len = found_comment(line, line_nbr, index, len)) == -1)
			print_err("Error : COMMENT_CMD_STRING not found", line, -1, -1);
		else if (len > COMMENT_LENGTH)
			print_err("Error : comment length exceeds limit", line, -1, -1);
		*found_name_com = 2;
	}
}
