/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:05:35 by akhanye           #+#    #+#             */
/*   Updated: 2017/10/01 04:41:51 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printhex(unsigned char num)
{
	char hex[16];

	ft_bzero(hex, 16);
	ft_strcat(hex, "0123456789abcdef");
	if (num < 16)
		ft_putchar(hex[num]);
	else
	{
		ft_printhex(num / 16);
		ft_printhex(num % 16);
	}
}
