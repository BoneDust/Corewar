/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcuthead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 12:51:34 by gtshekel          #+#    #+#             */
/*   Updated: 2017/07/15 10:54:52 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcuthead(char **s, int c)
{
	char *temp;

	if (!*s)
		return (NULL);
	if (!(temp = ft_strsub(*s, c, ft_strlen(*s) - c)))
		return (NULL);
	if (*s)
		free(*s);
	if (!(*s = (char*)malloc(ft_strlen(temp) + 1)))
		return (NULL);
	ft_bzero((void*)(*s), ft_strlen(temp) + 1);
	ft_strcpy(*s, temp);
	free(temp);
	temp = NULL;
	return (*s);
}
