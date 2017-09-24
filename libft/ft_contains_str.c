/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:19:17 by gtshekel          #+#    #+#             */
/*   Updated: 2017/08/16 13:19:36 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_contains_str(const char **argv, const char *str, int len)
{
	int		index;

	index = 0;
	while (index < len)
	{
		if (ft_strequ(argv[index], str))
			return (1);
		index++;
	}
	return (0);
}
