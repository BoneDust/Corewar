/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 09:54:56 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 15:14:12 by nrarane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void			join(char *buf, char *err1, char *err2)
{
	ft_strcpy(buf, err1);
	ft_strcat(buf, err2);
}

static void		check_n_option(char *option, char **v, t_arena **arena, int i)
{
	if (ft_strequ(option, "-n"))
	{
		(*arena)->n = 1;
		if ((*arena)->players == MAX_PLAYERS)
			exit_prog("\nError : Option after MAX_PLAYERS were loaded", arena);
		else if (v[i + 2] && v[i + 2][0] != '-')
		{
			if (ft_atoi(v[i + 1]) > 4)
				exit_prog("\nError : int after -n exceeds MAX_PLAYERS", arena);
			if (ft_atoi(v[i + 1]) < (*arena)->avail_n)
				exit_prog("\nError : Player number duplicates found", arena);
			else if (ft_atoi(v[i + 1]) == (*arena)->avail_n)
			{
				(*arena)->p_names[(*arena)->avail_n - 1] = ft_strdup(v[i + 2]);
				(*arena)->avail_n++;
			}
			else if (ft_atoi(v[i + 1]) > (*arena)->avail_n)
				(*arena)->p_names[ft_atoi(v[i + 1]) - 1] = ft_strdup(v[i + 2]);
		}
		else
			exit_prog("\nError : champion expected after -n option.", arena);
	}
}

static t_bool	get_option_value(char *option, char **v, t_arena **ar, int i)
{
	char	err[MAX_ERROR];

	ft_bzero(err, MAX_ERROR);
	if (!v[i + 1] || !ft_is_number(v[i + 1]))
	{
		join(err, "\nError : int expected after option ", option);
		exit_prog(err, ar);
	}
	if (ft_strequ(option, "-dump") && (*ar)->dump > 0)
		exit_prog("\nError : Option -dump is already defined.", ar);
	if (ft_strequ(option, "-dump") && (*ar)->players > 0)
		exit_prog("\nError : -dump must be defined before champs.", ar);
	if (ft_out_of_int_range(v[i + 1]) || ft_atoi(v[i + 1]) <= 0)
	{
		join(err, "\nError : An integer > 0 is expected after option ", option);
		exit_prog(err, ar);
	}
	(*ar)->dump = ft_strequ(option, "-dump") ? ft_atoi(v[i + 1]) : (*ar)->dump;
	check_n_option(option, v, ar, i);
	return (TRUE);
}

static t_bool	option_ok(char *op, char **av, t_arena **arena, int i)
{
	if (ft_strequ(op, "-dump") || ft_strequ(op, "-n"))
		return (get_option_value(op, av, arena, i));
	return (FALSE);
}

t_bool			get_options(int ac, char **av, char *err, t_arena **arena)
{
	int		i;

	i = 0;
	ft_bzero(err, MAX_ERROR);
	while (++i < ac)
	{
		if (av[i][0] == '-' && !option_ok(av[i], av, arena, i))
		{
			ft_strcpy(err, "\nError : Invalid option ");
			ft_strcat(err, av[i]);
			return (FALSE);
		}
		if (av[i][0] != '-' && av[i - 1][0] != '-')
		{
			(*arena)->players++;
			if (!(*arena)->n)
				(*arena)->p_names[(*arena)->avail_n++ - 1] = ft_strdup(av[i]);
			(*arena)->n = 0;
		}
		if ((*arena)->players > MAX_PLAYERS)
			exit_prog("\nError : Number of champs exceeds limit set.", arena);
	}
	if ((*arena)->players == 0)
		exit_prog("\nError : At least one champ is needed.", arena);
	return (TRUE);
}
