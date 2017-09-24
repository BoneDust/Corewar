/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:27:10 by gtshekel          #+#    #+#             */
/*   Updated: 2017/05/29 15:32:00 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *u_s;
	unsigned char u_c;

	u_s = (unsigned char*)s;
	u_c = (unsigned char)c;
	while (n--)
	{
		if (*u_s == u_c)
			return (u_s);
		u_s++;
	}
	return (NULL);
}
