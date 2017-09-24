/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:15:37 by gtshekel          #+#    #+#             */
/*   Updated: 2017/07/15 10:47:07 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	count;

	index = 0;
	while (big[index] != '\0' && index < len)
	{
		count = 0;
		while (little[count])
		{
			if (little[count] == big[index + count])
				count++;
			else
				break ;
		}
		if (!little[count] && len >= index + count)
			return ((char*)(big + index));
		index++;
	}
	return (NULL);
}
