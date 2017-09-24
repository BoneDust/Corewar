/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:45:37 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/11 16:43:46 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;
	int		src_len;

	index = 0;
	src_len = ft_strlen((char*)src);
	if (len <= 0)
		return (dst);
	while (index < len)
	{
		if (index < src_len)
		{
			dst[index] = src[index];
			index++;
			continue;
		}
		dst[index] = '\0';
		index++;
	}
	return (dst);
}
