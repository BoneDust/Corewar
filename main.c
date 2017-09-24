/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:56:33 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/24 04:22:59 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static int	create_cor_file(char *filename)
{
	int		fd;
	char	*newfile;
	char	*tmp;

	tmp = ft_strsub(filename, 0, ft_strlen(filename) - 2);
	newfile = ft_strjoin(tmp, ".cor");
	if ((fd = open(newfile, O_CREAT | O_WRONLY, S_IWUSR | S_IRUSR)) == -1)
	{
		free(newfile);
		perror("Error: ");
		exit(1);
	}
	free(tmp);
	free(newfile);
	return (fd);
}

int			main(int argc, char **argv)
{
	int read_fd;
	int write_fd;
	int	file_index;

	file_index = 1;
	if (argc < 2)
	{
		ft_putstr("Usage: ./asm [filename] ...\n");
		return (0);
	}
	while (file_index < argc)
	{
		error_analysis(argv[file_index], 0, 0, 0);
		if ((read_fd = open(argv[file_index], O_RDONLY)) == -1)
		{
			perror("Error :");
			return (0);
		}
		write_fd = create_cor_file(argv[file_index]);
		encode_to_file(write_fd, read_fd, 0);
		close(read_fd);
		close(write_fd);
		file_index++;
	}
	return (0);
}
