/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:40:13 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/01 13:28:04 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int			bytes_to_int(unsigned char *bytes, int size)
{
	int				num;
	unsigned char	temp_num[4];

	num = 0;
	ft_bzero(temp_num, 4);
	if (size == 1)
		return ((int)bytes[0]);
	else if (size == IND_SIZE)
	{
		temp_num[3] = (bytes[0] > 240) ? 0xff : 0x00;
		temp_num[2] = (bytes[0] > 240) ? 0xff : 0x00;
		temp_num[1] = bytes[0];
		temp_num[0] = bytes[1];
		num = (*((int *)temp_num));
		return (num);
	}
	temp_num[3] = bytes[0];
	temp_num[2] = bytes[1];
	temp_num[1] = bytes[2];
	temp_num[0] = bytes[3];
	num = (*((int *)temp_num));
	return (num);
}

void		verify_head(unsigned char *buf, t_champ **ch, t_arena **arena, int j)
{
	int				i;
	unsigned char	p_size[4];
	char			err[MAX_ERROR];

	ft_bzero((*ch)->name, PROG_NAME_LENGTH + 1);
	ft_bzero((*ch)->comment, COMMENT_LENGTH + 1);
	if (buf[0] != 0x00 || buf[1] != 0xea || buf[2] != 0x83 || buf[3] != 0xf3)
	{
		free(*ch);
		exit_prog("\nError : Champion contains invalid magic number.", arena);
	}
	i = 4;
	ft_memcpy((*ch)->name, buf + i, PROG_NAME_LENGTH);
	i += PROG_NAME_LENGTH + 4;
	ft_memcpy((void*)p_size, (const void*)(buf + i), 4);
	(*ch)->player_size = bytes_to_int(p_size, 4);
	i += 4;
	if ((*ch)->player_size <= 0 || (*ch)->player_size > CHAMP_MAX_SIZE)
	{
		free(*ch);
		join(err, "\nError : ", (*arena)->p_names[j]);
		ft_strcat(err, " size is zero or too large.");
		exit_prog(err, arena);
	}
	ft_memcpy((void*)(*ch)->comment, (const void*)(buf + i), COMMENT_LENGTH);
}

t_champ		*create_champ(t_arena **arena, int i, unsigned char *head, int bytes)
{
	t_champ			*champ;
	int				index;

	index = 0;
	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		return (NULL);
	verify_head(head, &champ, arena, i);
	champ->reg[0] = i + 1;
	champ->player_no = champ->reg[0];
	champ->alive = 0;
	champ->wait = 0;
	champ->run = 0;
	champ->carry = 0;
	champ->pc = 0;
	champ->next = NULL;
	while (++index < REG_NUMBER)
		champ->reg[index] = 0;
	ft_bzero((void*)champ->prog, CHAMP_MAX_SIZE);
	if ((bytes = read((*arena)->fd[i], champ->prog, champ->player_size)) < 0)
	{
		free(champ);
		exit_prog("\nError : Failed to read champion data.", arena);
	}
	return (champ);
}

void		add_to_champs(t_champ **champs, t_champ *champ)
{
	if (!*champs)
		*champs = champ;
	else
	{
		champ->next = *champs;
		*champs = champ;
	}
}

void		read_champs(t_arena **arena)
{
	int				i;
	int				r;
	unsigned char	header[HEADER_SIZE];
	t_champ			*champ;
	char			err[MAX_ERROR];

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if ((*arena)->p_names[i] == NULL)
			continue ;
		ft_bzero(header, HEADER_SIZE);
		if ((r = read((*arena)->fd[i], header, HEADER_SIZE)) == -1)
		{
			join(err, "\nError : Champ data read fail ", (*arena)->p_names[i]);
			exit_prog(err, arena);
		}
		champ = create_champ(arena, i, header, r);
		if (!champ)
			exit_prog("\nError : memory allocation for a champ failed.", arena);
		add_to_champs(&(*arena)->champs, champ);
		close((*arena)->fd[i]);
	}
}
