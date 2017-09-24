/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_items_in_grid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:04:18 by gtshekel          #+#    #+#             */
/*   Updated: 2017/08/16 13:20:35 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_items_in_grid(void **grid)
{
	int index;

	index = 0;
	while (grid[index])
		index++;
	return (index);
}
