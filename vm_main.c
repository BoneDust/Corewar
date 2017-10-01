/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmayibo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 12:26:02 by mmayibo           #+#    #+#             */
/*   Updated: 2017/10/01 11:13:19 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				exit_prog(char *msg, t_arena **arena)
{
	ft_putendl(msg);
	destroy_arena(arena);
	exit(0);
}

static void		print_winner(t_arena *arena)
{
	if (arena->last_live)
	{
		ft_putstr("\nPlayer ");
		ft_putnbr(arena->last_live);
		ft_putstr(" (");
		ft_putstr(arena->winner);
		ft_putstr(") won\n\t");
		ft_putendl(arena->winner_comment);
	}
	else
		ft_putendl("No player won the game.");
}

static t_arena	*init_arena(void)
{
	int		i;
	t_arena	*arena;

	i = -1;
	if (!(arena = (t_arena*)malloc(sizeof(t_arena))))
		return (NULL);
	arena->dump = 0;
	ft_bzero((char*)arena->arena, MEM_SIZE);
	arena->cycles = 0;
	arena->n = 0;
	arena->avail_n = 1;
	arena->cycles_to_die = CYCLE_TO_DIE;
	arena->players = 0;
	arena->p_names = ft_alloc_grid(MAX_PLAYERS);
	arena->last_live = 0;
	ft_bzero(arena->winner, PROG_NAME_LENGTH + 1);
	ft_bzero(arena->winner_comment, COMMENT_LENGTH + 1);
	arena->max_checks = MAX_CHECKS;
	arena->champs = NULL;
	while (++i < MAX_PLAYERS)
		arena->fd[i] = -1;
	return (arena);
}

int				main(int ac, char **av)
{
	char	err[MAX_ERROR];
	t_func	f[16];
	t_arena	*arena;
	int		cycles;
	int		cycles_2d_counter;

	cycles = 0;
	arena = init_arena();
	cycles_2d_counter = 0;
	if (ac < 2)
		exit_prog(ARGS_ERR, &arena);
	if (!get_options(ac, av, err, &arena))
		exit_prog(err, &arena);
	get_fds(&arena);
	read_champs(&arena);
	load_arena(&arena);
	fill_functions(f);
	run_cycles(&arena, f, &cycles_2d_counter, &cycles);
	if (cycles != arena->dump)
		print_winner(arena);
	destroy_arena(&arena);
	return (0);
}
