/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 10:52:56 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 17:52:38 by nrarane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		process_instruction(t_champ *champ, t_arena **arena, t_func *f)
{
	unsigned char	op;

	op = (*arena)->arena[champ->pc];
	if (champ->wait == champ->run)
	{
		if (op >= 1 && op <= 16)
			f[op - 1](arena, &champ);
		else
			champ->pc++;
		champ->wait = 0;
	}
	champ->pc %= MEM_SIZE;
}

void			fill_functions(t_func *f)
{
	f[0] = &ft_live;
	f[1] = &ft_ld;
	f[2] = &ft_st;
	f[3] = &ft_add;
	f[4] = &ft_sub;
	f[5] = &ft_and;
	f[6] = &ft_or;
	f[7] = &ft_xor;
	f[8] = &ft_zjmp;
	f[9] = &ft_ldi;
	f[10] = &ft_sti;
	f[11] = &ft_fork;
	f[12] = &ft_lld;
	f[13] = &ft_lldi;
	f[14] = &ft_lfork;
	f[15] = &ft_aff;
}

static t_champ	*remove_player(int cycles, t_champ *champ, t_arena **arena)
{
	ft_putstr("\nPlayer who died this cycle (");
	ft_putnbr(cycles);
	ft_putstr(") : Player ");
	ft_putnbr(champ->player_no);
	ft_putstr(" (");
	ft_putstr(champ->name);
	ft_putendl(")");
	return (destroy_dead_champ(arena, champ->player_no));
}

static int		check_alive(int cycles, t_arena **arena, int total_lives)
{
	t_champ	*champ;

	champ = (*arena)->champs;
	while (champ)
	{
		if (!champ->alive)
			champ = remove_player(cycles, champ, arena);
		else
		{
			total_lives += champ->alive;
			champ->alive = 0;
			champ = champ->next;
		}
	}
	if (total_lives >= NBR_LIVE)
		(*arena)->cycles_to_die -= CYCLE_DELTA;
	else
		(*arena)->max_checks--;
	if (!(*arena)->max_checks && ((*arena)->max_checks = MAX_CHECKS) > 0)
		(*arena)->cycles_to_die -= CYCLE_DELTA;
	return ((*arena)->champs && total_lives ? TRUE : FALSE);
}

void			run(t_arena **arena, t_func *f, int *c2d_counter, int *cycle)
{
	t_champ *champ;
	int		battle_continues;

	battle_continues = TRUE;
	while (battle_continues && (*arena)->cycles_to_die > 0)
	{
		*c2d_counter += 1;
		*cycle += 1;
		champ = (*arena)->champs;
		while (champ)
		{
			set_run((*arena)->arena[champ->pc], &champ);
			champ->wait++;
			process_instruction(champ, arena, f);
			champ = champ->next;
		}
		if (*c2d_counter >= (*arena)->cycles_to_die)
		{
			battle_continues = check_alive(*cycle, arena, 0);
			*c2d_counter = 0;
		}
		if (*cycle == (*arena)->dump)
			dump_memory(arena);
	}
}
