# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/02 19:50:44 by gtshekel          #+#    #+#              #
#    Updated: 2017/09/23 04:42:24 by gtshekel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wall -Werror

CC = gcc

SRC = ft_atoi.c	ft_memalloc.c	ft_putchar.c	ft_strcat.c	ft_striter.c	ft_strncmp.c	ft_strsub.c\
	ft_bzero.c	ft_memccpy.c	ft_putchar_fd.c	ft_strchr.c	ft_striteri.c	ft_strncpy.c	ft_strtrim.c\
	ft_isalnum.c	ft_memchr.c	ft_putendl.c	ft_strclr.c	ft_strjoin.c	ft_strnequ.c	ft_tolower.c\
	ft_isalpha.c	ft_memcmp.c	ft_putendl_fd.c	ft_strcmp.c	ft_strlcat.c	ft_strnew.c		ft_toupper.c\
	ft_itoa.c	ft_memset.c		ft_putstr_fd.c	ft_strequ.c		ft_strncat.c	ft_strstr.c		ft_isprint.c\
	ft_memmove.c	ft_putstr.c	ft_strdup.c	ft_strmapi.c	ft_strsplit.c	ft_isdigit.c	ft_memdel.c\
	ft_putnbr_fd.c	ft_strdel.c	ft_strmap.c	ft_strrchr.c	ft_isascii.c	ft_memcpy.c		ft_putnbr.c\
	ft_strcpy.c	ft_strlen.c	ft_strnstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstmap.c\
	ft_lstiter.c ft_strcuthead.c ft_addnbr.c ft_abs.c get_next_line.c destroy_fd.c ft_is_number.c ft_contains.c\
	ft_destroy_2d.c ft_htoi.c ft_items_in_grid.c ft_contains_str.c ft_out_of_int_range.c ft_replace.c\
	ft_count.c

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm  -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean	all

