/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:51:08 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/04 10:59:32 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long int	ret;
	int					sign;
	char				*n_str;

	sign = 1;
	ret = 0;
	n_str = (char*)str;
	while (*n_str == ' ' || *n_str == '\n' || *n_str == '\t' || *n_str == '\r'
	|| *n_str == '\v' || *n_str == '\f')
		n_str++;
	if (*n_str == '-' || *n_str == '+')
	{
		if (*n_str++ == '-')
			sign = -1;
	}
	while (ft_isdigit(*n_str))
		ret = ret * 10 + (*n_str++ - '0');
	if (ret > 9223372036854775807)
		return (sign > 0 ? -1 : 0);
	return (sign * ret);
}
