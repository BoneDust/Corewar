/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:43:16 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/13 13:42:36 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, const char *s2, size_t n)
{
	int ret;

	if (!s1 || !s2)
		return (0);
	ret = ft_strncmp(s1, s2, n);
	if (ret == 0)
		return (1);
	return (0);
}
