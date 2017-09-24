/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:37:51 by gtshekel          #+#    #+#             */
/*   Updated: 2017/08/08 14:38:05 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t index;
	size_t length;

	index = 0;
	length = ft_strlen(s1);
	while (s2[index] != '\0' && index < n)
		s1[length++] = s2[index++];
	s1[length] = '\0';
	return (s1);
}
