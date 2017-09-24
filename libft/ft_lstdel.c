/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:23:58 by gtshekel          #+#    #+#             */
/*   Updated: 2017/06/18 08:30:26 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = (*alst);
	while (temp)
	{
		del(temp->content, temp->content_size);
		free((*alst));
		(*alst) = NULL;
		temp = temp->next;
		(*alst) = temp;
	}
}
