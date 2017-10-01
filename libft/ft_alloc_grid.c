/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:16:53 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/22 10:38:41 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_alloc_grid(size_t n)
{
	char	**grid;
	int		index;

	if (!(grid = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	index = 0;
	while (index < n + 1)
		grid[index++] = NULL;
	return (grid);
}
