/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrarane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 11:30:29 by nrarane           #+#    #+#             */
/*   Updated: 2017/09/24 11:30:42 by nrarane          ###   ########.fr       */
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
