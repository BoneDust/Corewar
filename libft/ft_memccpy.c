/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:16:48 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/03 11:08:16 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	u_c;
	unsigned char	*u_dst;
	unsigned char	*u_src;
	size_t			index;

	u_c = (unsigned char)c;
	u_dst = (unsigned char*)dst;
	u_src = (unsigned char*)src;
	index = 0;
	while (index++ < n)
	{
		if (*u_src == u_c)
		{
			*u_dst = u_c;
			u_dst++;
			return (u_dst);
		}
		*u_dst++ = *u_src++;
	}
	return (NULL);
}
