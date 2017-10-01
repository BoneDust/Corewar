/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtshekel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 06:24:39 by gtshekel          #+#    #+#             */
/*   Updated: 2017/09/26 10:29:43 by gtshekel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd		*lstnew(int fd)
{
	t_fd	*newlist;

	newlist = NULL;
	if (!(newlist = (t_fd*)malloc(sizeof(t_fd))))
		return (NULL);
	newlist->fd = fd;
	if (!(newlist->store = ft_strnew(BUFF_SIZE)))
		return (NULL);
	newlist->next = NULL;
	return (newlist);
}

static t_fd		*getlist(t_fd **lst, int fd)
{
	t_fd	*ret;
	t_fd	*tmp;

	tmp = *lst;
	ret = NULL;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		ret = lstnew(fd);
		ret->next = *lst;
		*lst = ret;
		return (*lst);
	}
	return (tmp);
}

static int		read_into_storage(const int fd, char **store)
{
	char	*temp1;
	char	*temp2;
	int		bytes_read;

	if (*store == NULL)
		return (-1);
	temp1 = ft_strdup(*store);
	temp2 = ft_strnew(BUFF_SIZE);
	if (!temp1 || !temp2)
		return (-1);
	bytes_read = read(fd, temp2, BUFF_SIZE);
	if (*store)
		free(*store);
	if (!(*store = (char*)malloc(ft_strlen(temp1) + bytes_read + 1)))
		return (-1);
	ft_bzero(*store, ft_strlen(temp1) + bytes_read + 1);
	ft_strcpy(*store, temp1);
	ft_strcat(*store, temp2);
	free(temp1);
	free(temp2);
	if (bytes_read > 0)
		return (1);
	return (bytes_read == 0 ? 0 : -1);
}

static int		get_line(int fd, char **line, char **store, int bytes_read)
{
	char	*tmp;
	int		len;

	while ((bytes_read > 0) && !(tmp = ft_strchr(*store, '\n')))
		bytes_read = read_into_storage(fd, store);
	if (ft_strlen(*store))
		bytes_read = 1;
	if (bytes_read == -1)
		return (-1);
	len = (tmp ? ft_strlen(*store) - ft_strlen(tmp) : ft_strlen(*store));
	if (*line)
		free(*line);
	if (!(*line = ft_strnew(len)))
		return (-1);
	ft_strncpy(*line, *store, len);
	if (tmp)
		ft_strcuthead(&*store, len + 1);
	else
		ft_strcuthead(&*store, len);
	return (bytes_read);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd	*list;
	t_fd		*item;
	int			bytes_read;

	if (fd < 0)
		return (-1);
	if (!list && !(list = lstnew(fd)))
		return (-1);
	item = getlist(&list, fd);
	bytes_read = BUFF_SIZE;
	bytes_read = get_line(fd, line, &item->store, bytes_read);
	if (bytes_read > 0)
		return (1);
	if (bytes_read == 0)
		destroy_fd(fd, &list);
	return (bytes_read == 0 ? 0 : -1);
}
