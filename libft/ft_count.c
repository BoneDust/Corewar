/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 04:26:26 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/23 04:28:27 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count(char *s, char c)
{
	int counting;
	int	index;

	counting = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			counting++;
		index++;
	}
	return (counting);
}
