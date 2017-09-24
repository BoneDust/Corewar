/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_opcodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamashil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:41:47 by pamashil          #+#    #+#             */
/*   Updated: 2017/09/23 23:23:55 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

static unsigned char		sec_instructs(char *str)
{
	unsigned char	opcode;

	opcode = 0;
	if (ft_strequ(str, "zjmp"))
		opcode = 9;
	else if (ft_strequ(str, "ldi"))
		opcode = 10;
	else if (ft_strequ(str, "sti"))
		opcode = 11;
	else if (ft_strequ(str, "fork"))
		opcode = 12;
	else if (ft_strequ(str, "lld"))
		opcode = 13;
	else if (ft_strequ(str, "lldi"))
		opcode = 14;
	else if (ft_strequ(str, "lfork"))
		opcode = 15;
	else if (ft_strequ(str, "aff"))
		opcode = 16;
	return (opcode);
}

static unsigned char		first_instructs(char *str)
{
	unsigned char	opcode;

	opcode = 0;
	if (ft_strequ(str, "live"))
		opcode = 1;
	else if (ft_strequ(str, "ld"))
		opcode = 2;
	else if (ft_strequ(str, "st"))
		opcode = 3;
	else if (ft_strequ(str, "add"))
		opcode = 4;
	else if (ft_strequ(str, "sub"))
		opcode = 5;
	else if (ft_strequ(str, "and"))
		opcode = 6;
	else if (ft_strequ(str, "or"))
		opcode = 7;
	else if (ft_strequ(str, "xor"))
		opcode = 8;
	return (opcode);
}

unsigned char				ft_get_opcode(char *str)
{
	return (first_instructs(str) ? first_instructs(str) : sec_instructs(str));
}

unsigned char				ft_get_encoding(int *param_types, int n_params)
{
	int					i;
	int					j;
	static char			ret[9];

	i = -1;
	j = -2;
	ret[8] = '\0';
	while (i < 7)
		ret[++i] = '0';
	i = -1;
	while (++i < n_params && (j += 2) >= 0)
	{
		if (param_types[i] == T_REG)
		{
			ret[j] = '0';
			ret[j + 1] = '1';
		}
		else
		{
			ret[j] = '1';
			ret[j + 1] = (param_types[i] == T_DIR ? '0' : ret[j + 1]);
			ret[j + 1] = (param_types[i] == T_IND ? '1' : ret[j + 1]);
		}
	}
	return (bintodec(ret));
}
