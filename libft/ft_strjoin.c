/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:41:26 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/13 13:28:49 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (ret == NULL)
		return (NULL);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	return (ret);
}
