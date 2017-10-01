/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:45:15 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/27 14:47:50 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest;
	const char		*source;

	dest = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		*dest++ = *source++;
		i++;
	}
	return (dst);
}
