/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_ps.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:40:11 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 12:41:01 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_gnl	*new_lst(int fd)
{
	t_gnl	*newlst;

	newlst = malloc(sizeof(t_gnl));
	if (!newlst)
		return ((void *)0);
	newlst->fd = fd;
	newlst->next = NULL;
	newlst->offset = BUFFER_SIZE;
	newlst->rbytes = BUFFER_SIZE;
	newlst->res_len = 0;
	newlst->len = 1;
	return (newlst);
}

t_gnl	*find_fd_node(t_gnl **head, t_gnl **cur, int fd)
{
	if (!*head)
	{
		*head = new_lst(fd);
		if (!*head)
			return ((void *)0);
	}
	*cur = *head;
	while (*cur && (*cur)->fd != fd)
	{
		if (!(*cur)->next)
		{
			(*cur)->next = new_lst(fd);
			if (!(*cur)->next)
				return ((void *)0);
		}
		*cur = (*cur)->next;
	}
	return (*cur);
}

ssize_t	read_line(t_gnl **head, char *res, t_gnl *cur, int fd)
{
	cur->rbytes = read(fd, cur->buff, BUFFER_SIZE);
	if (cur->rbytes < 0)
	{
		gnl_del(head, cur);
		free (res);
		return (0);
	}
	cur->offset = 0;
	cur->len = 1;
	return (1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((src[i] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

void	gnl_del(t_gnl **head, t_gnl *cur)
{
	t_gnl	*temp;

	if (*head == cur)
	{
		*head = cur->next;
		free (cur);
		return ;
	}
	temp = *head;
	while (temp->next)
	{
		if (temp->next == cur)
		{
			temp->next = cur->next;
			free(cur);
			return ;
		}
		temp = temp->next;
	}
}
