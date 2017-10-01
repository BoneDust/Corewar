/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:19:17 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/13 12:38:14 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_contains_str(char **argv, char *str, int len)
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
