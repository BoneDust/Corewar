# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 13:08:25 by gtshekel          #+#    #+#              #
#    Updated: 2017/09/24 03:57:49 by gtshekel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = asm

NAME_2 = corewar

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBS = -L libft/ -lft

INCLUDES = ft_corewar.h op.h

SRC_1 =  main.c process_opcodes.c write_to_file.c labels_one.c labels_two.c \
		 get_param_types.c file_processing_one.c file_processing_two.c \
		 getbytes.c destruction.c error_handling.c check_header.c\
		 check_instruction.c print_errors.c verify_arg_types1.c verify_arg_types2.c\
		 verify_values.c

all: $(NAME_1)

$(NAME_1):
	$(MAKE) -C libft/
	$(CC) -o $(NAME_1) $(SRC_1) $(CFLAGS)  $(LIBS)
	
#$(NAME_2):
#	$(MAKE) -C libft/ re
#	$(CC) -o $(NAME_2) $(SRC) checker.c $(CFLAGS)  $(LIBS)
	
norme: 
	@echo "\t\t<<<< Norminette all .c files >>>>\n"
	find . -name '*.c' -exec norminette {} \;
	@echo "\t\t<<<< Norminette all .h files >>>>\n"
	find . -name '*.h' -exec norminette {} \;

clean:
	$(MAKE) -C libft/ clean

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME_1)
#	rm -f $(NAME_2)

re: fclean all
	$(MAKE) -C libft fclean re
