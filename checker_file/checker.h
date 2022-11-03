/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:36:36 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 13:49:33 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_gnl
{
	int				fd;
	struct s_gnl	*next;
	char			buff[BUFFER_SIZE];
	ssize_t			offset;
	ssize_t			rbytes;
	ssize_t			len;
	ssize_t			res_len;
}	t_gnl;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_info
{
	int				*array;
	int				size_a;
	int				size_b;
	int				pre_pivot;
	int				count;
	struct s_node	*top_a;
	struct s_node	*bottom_a;
	struct s_node	*top_b;
	struct s_node	*bottom_b;
}	t_info;

typedef struct s_command_info
{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
	int	big_pivot;
	int	small_pivot;
}	t_command_info;

char	*get_next_line(int fd);
t_gnl	*new_lst(int fd);
t_gnl	*find_fd_node(t_gnl **head, t_gnl **cur, int fd);
ssize_t	read_line(t_gnl **head, char *res, t_gnl *cur, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	gnl_del(t_gnl **head, t_gnl *cur);

#endif