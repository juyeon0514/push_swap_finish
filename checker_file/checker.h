/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:36:36 by juykang           #+#    #+#             */
/*   Updated: 2022/11/05 14:59:14 by juykang          ###   ########seoul.kr  */
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

int		ft_atoi_ps(const char *str);
int		check_str_size(int argc, char **argv);
int		*make_av_to_array(int argc, char **argv, int size);
void	make_arr_to_stack(t_info *info, int *array, int size);
void	array_sort(int *array, int size, int index);

int		check_size_split_str(char **split_str);
void	ft_free_str(char **array);
void	make_str_to_array(int *array, int *arr_idx, char **str);
int		ft_isdigit(int c);
int		check_arg(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

char	**ft_split(char const *s, char c);

int		ft_error(int flag);
t_node	*stack_init(void);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_sort(t_info *info);
void	do_operation(t_info *info, char *str);
void	ft_checker(t_info *info);

void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);

void	pa(t_info *info);
void	pb(t_info *info);

void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
#endif