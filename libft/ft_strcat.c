/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:09:27 by gtshekel          #+#    #+#             */
/*   Updated: 2017/05/29 16:44:45 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int length;

	length = ft_strlen(s1);
	index = 0;
	while (s2[index] != '\0')
		s1[length++] = s2[index++];
	s1[length] = '\0';
	return (s1);
}
