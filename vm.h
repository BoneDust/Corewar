/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:40:17 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 12:30:25 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft/libft.h"
# include "op.h"
# define MAX_ERROR 1000
# define HEADER_SIZE (PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
# define ARGS_ERR "./corewar [-dump cycles] [[-n nbr] c1.cor] ..."

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_instr
{
	char			size;
	int				value;
	struct s_instr	*next;
}					t_instr;

typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	player_size;
	int				alive;
	int				player_no;
	int				reg[REG_NUMBER];
	int				carry;
	unsigned char	prog[CHAMP_MAX_SIZE];
	int				pc;
	struct s_champ	*next;
	int				wait;
	int				run;
}					t_champ;

typedef struct		s_arena
{
	int				dump;
	int				n;
	int				avail_n;
	char			**p_names;
	int				last_live;
	char			winner[PROG_NAME_LENGTH + 1];
	char			winner_comment[COMMENT_LENGTH + 1];
	int				max_checks;
	unsigned char	arena[MEM_SIZE];
	int				cycles;
	int				cycles_to_die;
	int				players;
	t_champ			*champs;
	int				fd[MAX_PLAYERS];
}					t_arena;

typedef void		(*t_func)(t_arena **, t_champ **);

void				arena_val(unsigned char *a, int s, int p, unsigned char *b);
void				to_arena(t_arena **are, unsigned char *byte, int b, int pc);
void				add_to_champs(t_champ **all_champs, t_champ *champ);
void				create_fork_champ(t_champ *champ, t_arena **arena, int ind);
void				set_run(unsigned char op, t_champ **champ);
void				run_cycles(t_arena **arena, t_func *f, int *count, int *cy);
void				fill_functions(t_func *f);
void				destroy_arena(t_arena **arena);
t_bool				get_options(int ac, char **av, char *err, t_arena **arena);
int					exit_prog(char *message, t_arena **arena);
t_bool				get_fds(t_arena **arena);
void				join(char *buf, char *err1, char *err2);
void				read_champs(t_arena **arena);
void				dump_memory(t_arena **arena);
void				load_arena(t_arena **arena);
int					bytes_to_int(unsigned char *bytes, int size);
int					get_a_value(int c, int pc, unsigned char *a);
void				decode(unsigned char op, unsigned char e, unsigned char *s);
void				to_big_endian(unsigned char *num);

/*
**		opcode functions
*/
void				ft_live(t_arena **arena, t_champ **champ);
void				ft_and(t_arena **arena, t_champ **champ);
void				ft_sti(t_arena **arena, t_champ **champ);
void				ft_ld(t_arena **arena, t_champ **champ);
void				ft_st(t_arena **arena, t_champ **champ);
void				ft_add(t_arena **arena, t_champ **champ);
void				ft_sub(t_arena **arena, t_champ **champ);
void				ft_or(t_arena **arena, t_champ **champ);
void				ft_xor(t_arena **arena, t_champ **champ);
void				ft_zjmp(t_arena **arena, t_champ **champ);
void				ft_ldi(t_arena **arena, t_champ **champ);
void				ft_fork(t_arena **arena, t_champ **champ);
void				ft_lld(t_arena **arena, t_champ **champ);
void				ft_lldi(t_arena **arena, t_champ **champ);
void				ft_lfork(t_arena **arena, t_champ **champ);
void				ft_aff(t_arena **arena, t_champ **champ);

#endif
