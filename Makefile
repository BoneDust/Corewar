# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 13:08:25 by gtshekel          #+#    #+#              #
#    Updated: 2017/10/01 04:47:42 by gtshekel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = asm

NAME_2 = corewar

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBS = -L libft/ -lft

INCLUDES = ft_corewar.h op.h

SRC_1 =  asm_main.c process_opcodes.c write_to_file.c labels_one.c labels_two.c \
		 get_param_types.c file_processing_one.c file_processing_two.c \
		 getbytes.c destruction.c error_handling.c check_header.c\
		 check_instruction.c print_errors.c verify_arg_types1.c verify_arg_types2.c\
		 verify_values.c


SRC_FLDR	=	src/
SRC_INSTR	=	src/instructions/

SRC_2		=	vm_main.c						\
				$(SRC_FLDR)ft_getoptions.c		\
				$(SRC_FLDR)destruction.c		\
				$(SRC_FLDR)get_fd.c				\
				$(SRC_FLDR)champs.c				\
				$(SRC_FLDR)arena.c				\
				$(SRC_FLDR)cycles.c				\
				$(SRC_FLDR)values.c				\
				$(SRC_FLDR)decode.c				\
				$(SRC_INSTR)ft_and.c			\
				$(SRC_INSTR)ft_zjmp.c			\
				$(SRC_INSTR)ft_sti.c			\
				$(SRC_INSTR)ft_live.c			\
				$(SRC_INSTR)ft_aff.c			\
				$(SRC_INSTR)ft_st.c				\
				$(SRC_INSTR)ft_add.c			\
				$(SRC_INSTR)ft_sub.c			\
				$(SRC_INSTR)ft_or.c				\
				$(SRC_INSTR)ft_xor.c			\
				$(SRC_INSTR)ft_ld.c				\
				$(SRC_INSTR)ft_ldi.c			\
				$(SRC_INSTR)ft_fork.c			\
				$(SRC_INSTR)ft_lld.c			\
				$(SRC_INSTR)ft_lldi.c			\
				$(SRC_INSTR)ft_lfork.c			\

all: $(NAME_1) $(NAME_2)

$(NAME_1):
	$(MAKE) -C libft/
	$(CC) -o $(NAME_1) $(SRC_1) $(CFLAGS)  $(LIBS)

$(NAME_2):
	$(MAKE) -C libft/ re
	$(CC) -o $(NAME_2) $(SRC_2) $(CFLAGS)  $(LIBS)

clean:
	$(MAKE) -C libft/ clean

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME_1)
	rm -f $(NAME_2)

re: fclean all
	$(MAKE) -C libft fclean re
