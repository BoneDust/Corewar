/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 11:55:02 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/10 08:40:23 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_number(char *s)
{
	int index;

	if (!s || ft_strlen(s) == 0)
		return (0);
	index = 0;
	if (s[index] == '+' || s[index] == '-')
		index++;
	while (s[index])
	{
		if (!ft_isdigit(s[index]))
			return (0);
		index++;
	}
	return (1);
}
