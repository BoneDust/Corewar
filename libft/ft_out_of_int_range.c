/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_of_int_range.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:21:34 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/24 00:01:12 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_out_of_int_range(const char *str)
{
	unsigned long int	ret;
	char				*n_str;

	ret = 0;
	n_str = (char*)str;
	while (*n_str == ' ' || *n_str == '\n' || *n_str == '\t' || *n_str == '\r'
			|| *n_str == '\v' || *n_str == '\f')
		n_str++;
	if (*n_str == '-' || *n_str == '+')
		n_str++;
	while (ft_isdigit(*n_str))
		ret = ret * 10 + (*n_str++ - '0');
	if (ret > 9223372036854775807)
		return (1);
	return (0);
}
