/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 10:53:21 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/20 15:30:10 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*ret;
	size_t	len_little;

	ret = (char*)big;
	len_little = ft_strlen((char*)little);
	if (*ret && len_little == 0)
		return (ret);
	while (*ret)
	{
		if (ft_strncmp(ret, little, len_little) == 0)
			return (ret);
		ret++;
	}
	if (ret == little)
		return (ret);
	return (NULL);
}
