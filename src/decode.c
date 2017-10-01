/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:06:13 by gtshekel          #+#    #+#             */
/*   Updated: 2017/10/01 11:24:00 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	set_run(unsigned char op, t_champ **champ)
{
	if (op == 1 || op == 4 | op == 5 || op == 13)
		(*champ)->run = 10;
	else if (op == 2 || op == 3)
		(*champ)->run = 5;
	else if (op == 6 || op == 7 || op == 8)
		(*champ)->run = 6;
	else if (op == 10 || op == 11)
		(*champ)->run = 25;
	else if (op == 9)
		(*champ)->run = 20;
	else if (op == 12)
		(*champ)->run = 800;
	else if (op == 14)
		(*champ)->run = 50;
	else if (op == 15)
		(*champ)->run = 1000;
	else
		(*champ)->run = 2;
}

int		get_type_size(unsigned char op, unsigned char type)
{
	if (type == REG_CODE)
		return (1);
	else if (type == DIR_CODE)
	{
		if ((op >= 9 && op <= 12) || op == 14 || op == 15)
			return (IND_SIZE);
		else
			return (DIR_SIZE);
	}
	else if (type == IND_CODE)
		return (IND_SIZE);
	else
		return (0);
}

void	decode(unsigned char op, unsigned char code, unsigned char *sizes)
{
	sizes[0] = code >> 6;
	sizes[1] = code << 2;
	sizes[1] = sizes[1] >> 6;
	sizes[2] = code << 4;
	sizes[2] = sizes[2] >> 6;
	sizes[0] = get_type_size(op, sizes[0]);
	sizes[1] = get_type_size(op, sizes[1]);
	sizes[2] = get_type_size(op, sizes[2]);
}
