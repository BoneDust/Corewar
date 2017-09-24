/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:44:55 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/24 04:22:01 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_H
# define FT_COREWAR_H
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_inst
{
	char			*line;
	int				line_nbr;
	int				index;
	int				bytes;
	unsigned char	opcode;
	int				hasencoding;
	unsigned char	encoding;
	int				n_params;
	int				indir_bytes;
	int				dir_bytes;
	int				param_types[MAX_ARGS_NUMBER];
	char			**params;
	int				param_v[MAX_ARGS_NUMBER];
	int				param_bytes[MAX_ARGS_NUMBER];
	struct s_inst	*next;
}					t_inst;

typedef struct		s_label
{
	char			*name;
	int				index;
	struct s_label	*next;
}					t_label;

void				print_lbl_err(t_inst *t, t_inst **d, t_label **l, int col);
void				print_dir_err(t_inst *t, t_inst **d, t_label **l, int col);
void				print_ind_err(t_inst *t, t_inst **d, t_label **l, int col);
void				print_reg_err(t_inst *t, t_inst **d, t_label **l, int col);
void				verify_reg_value(t_inst *t, t_inst **d, t_label **l, int i);
void				verify_ind_value(t_inst *t, t_inst **d, t_label **l, int i);
void				verify_dir_value(t_inst *t, t_inst **d, t_label **l, int i);
void				get_param_types(t_inst **inst);
int					verify_live_fork_lfork_aff_zjmp_arg(t_inst *t);
int					verify_add_sub_arg(t_inst *t);
int					verify_lld_ld_arg(t_inst *t);
int					verify_ldi_lldi_arg(t_inst *t);
int					verify_st_arg(t_inst *t);
int					verify_sti_arg(t_inst *t);
int					verify_and_or_xor(t_inst *t);
void				get_n_check_labels(t_inst **data, t_label **label);
int					found_label(t_label *labels, char *name);
void				print_inst_err(char *m, t_inst **d, t_label **l, t_inst *t);
void				print_err(char *msg, char **line, int line_nbr, int col);
void				check_instructions(int line_nbr, int fd);
void				check_header(char **line, int line_nbr, int *found);
void				error_analysis(char *file, int line_nbr, int f_n_c, int fd);
unsigned char		ft_get_opcode(char *str);
void				write_to_cor(t_inst *inst, t_header header, int fd);
int					is_label_only(char *line);
int					contains_label(char *line);
t_label				*create_label(char **line, int total_bytes);
void				create_all_lbls(t_label **label, t_inst **iter, int bytes);
void				add_label(t_label **label, t_label *newlabel);
int					get_bytes_in_line(const char *s, int bytes);
void				get_file(int fd, int line_nbr, t_inst **data, t_header *h);
int					get_number_of_params(unsigned char opcode);
int					get_lbl(char *item, int index, t_label *labels);
int					needslabel(char *param);
void				process_params(t_inst **inst, t_label *labels);
void				encode_to_file(int w_fd, int r_fd, int total_bytes);
unsigned char		bintodec(char *bin_no);
unsigned char		ft_get_encoding(int *param_types, int n_params);
void				destroy_labels(t_label *labels);
void				destroy_data(t_inst *data);
t_header			init_header(void);
void				get_string(char *str, char *line);
t_inst				*create_inst(char *line, int i, int line_nbr);
void				add_inst(t_inst **data, t_inst *ins);
#endif
