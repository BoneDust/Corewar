/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:36:50 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/26 10:37:01 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_replace(char **str, char a, char b)
{
	int		index;

	index = 0;
	while ((*str)[index])
	{
		if ((*str)[index] == a)
			(*str)[index] = b;
		index++;
	}
}
