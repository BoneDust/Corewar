/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 11:56:43 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/11 15:13:06 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_items(const char *s, char c)
{
	int		index;
	int		items;
	int		is_valid;

	is_valid = 0;
	index = 0;
	items = 0;
	while (s[index])
	{
		if (s[index] == c && is_valid)
		{
			items++;
			is_valid = 0;
		}
		else if (s[index] != c)
			is_valid = 1;
		index++;
	}
	if (is_valid)
		items++;
	return (items);
}

static void		fill_array(char **arr, const char *s, char c, int num)
{
	int		row;
	int		len;
	int		index;
	int		is_valid;

	is_valid = 0;
	row = 0;
	len = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == c && is_valid)
		{
			arr[row++] = ft_strsub(s, index - len, len);
			len = 0;
			is_valid = 0;
		}
		if (s[index++] != c)
		{
			len++;
			is_valid = 1;
		}
	}
	if (is_valid)
		arr[row] = ft_strsub(s, index - len, len);
}

char			**ft_strsplit(const char *s, char c)
{
	int		items;
	char	**ret;

	if (s == NULL)
		return (NULL);
	items = count_items(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (items + 1))))
		return (NULL);
	fill_array(ret, s, c, items);
	ret[items] = NULL;
	return (ret);
}
