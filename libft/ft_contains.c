/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 13:45:06 by gtshekel          #+#    #+#             */
/*   Updated: 2017/08/03 12:23:23 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_contains(char *s, char c)
{
	int index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (1);
		index++;
	}
	return (0);
}
