/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:13:43 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 10:46:37 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static int	get_champ_fd(char *player, t_arena **arena)
{
	char	err[MAX_ERROR];
	char	*sub;
	int		fd;

	if (ft_strlen(player) <= 4)
	{
		join(err, "\nError: Invalid player found : ", player);
		exit_prog(err, arena);
	}
	sub = ft_strsub(player, ft_strlen(player) - 4, 4);
	if (!ft_strequ(sub, ".cor"))
	{
		free(sub);
		join(err, "\nError: Invalid player found : ", player);
		exit_prog(err, arena);
	}
	if ((fd = open(player, O_RDONLY)) == -1)
	{
		free(sub);
		join(err, "\nError: Player ", player);
		ft_strcat(err, "  does not exist.");
		exit_prog(err, arena);
	}
	free(sub);
	return (fd);
}

t_bool		get_fds(t_arena **arena)
{
	int	index;

	index = 0;
	while (index < MAX_PLAYERS)
	{
		if ((*arena)->p_names[index] == NULL)
		{
			index++;
			continue ;
		}
		(*arena)->fd[index] = get_champ_fd((*arena)->p_names[index], arena);
		index++;
	}
	return (TRUE);
}
