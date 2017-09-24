/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 10:53:02 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/25 16:39:18 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(ret, size + 1);
	return (ret);
}
