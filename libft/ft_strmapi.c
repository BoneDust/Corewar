/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:45:45 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/18 08:20:59 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		index;

	if (!s)
		return (NULL);
	ret = ft_strnew(ft_strlen(s));
	if (ret == NULL)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	return (ret);
}
