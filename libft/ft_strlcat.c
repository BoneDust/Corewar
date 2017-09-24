/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:43:37 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/24 07:16:46 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	src_index;
	size_t	dst_len;
	size_t	src_len;
	size_t	temp_size;

	dst_len = (ft_strlen(dst) < size ? ft_strlen(dst) : size);
	temp_size = size - dst_len;
	index = dst_len;
	src_index = 0;
	src_len = ft_strlen(src);
	if (temp_size == 0)
		return (size + src_len);
	while (temp_size > 1 && src[src_index] != '\0')
	{
		dst[index] = src[src_index];
		index++;
		src_index++;
		temp_size--;
	}
	dst[index] = '\0';
	return (dst_len + src_len);
}
