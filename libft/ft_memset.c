/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:02:40 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/11 16:37:41 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*u_b;
	unsigned char	u_c;
	int				index;

	u_b = (unsigned char*)b;
	u_c = (unsigned char)c;
	index = 0;
	while (n--)
	{
		u_b[index++] = u_c;
	}
	return (u_b);
}
