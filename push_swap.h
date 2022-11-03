/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:35:31 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 12:09:05 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

int				ft_error(int flag);
t_node			*stack_init(void);
t_info			*ft_info_new(void);
int				main(int argc, char **argv);
char			**ft_split(char const *s, char c);
int				ft_atoi_ps(const char *str);
int				check_str_size(int argc, char **argv);
int				*make_av_to_array(int argc, char **argv, int size);
int				check_size_split_str(char **split_str);
void			ft_free_str(char **array);
void			make_str_to_array(int *array, int *arr_idx, char **str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			make_arr_to_stack(t_info *info, int *array, int size);
void			array_sort(int *array, int size, int index, t_info *info);
int				get_big_pivot(t_info *info, int size, int flag, int *arr);
int				get_small_pivot(t_info *info, int size, int flag, int *arr);
int				*make_stack_to_array(t_info *info, int size, int flag);
void			ft_print_stack(t_info *info);
void			ft_sort(t_info *info);
void			ft_a_to_b(t_info *info, int size);
void			ft_b_to_a(t_info *info, int size);
void			rotate_a(t_info *info, t_command_info *info2);
void			rotate_b(t_info *info, t_command_info *info2);
void			ft_sort_3(t_info *info);
void			ft_sort_big(t_info *info);
void			ft_sort(t_info *info);
void			back_use_rb_a(t_info *info, t_command_info *info2);
void			back_use_ra_a(t_info *info, t_command_info *info2);
void			back_use_rb_b(t_info *info, t_command_info *info2);
void			back_use_ra_b(t_info *info, t_command_info *info2);
void			info_command_init(t_command_info *info2);
void			ft_sort_2(t_info *info, int flag);
void			info_command_init(t_command_info *info2);
void			ft_sort_5(t_info *info);
void			switch_sort_5(t_info *info, int size, int flag);
void			ft_sort_small_a(t_info *info, int size);
void			ft_sort_5_a(t_info *info, int size);
void			ft_sort_5_b(t_info *info, int size);
int				get_mid_data(t_info *info, int size, int flag);
int				ft_max(int a, int b);
void			ft_sort_3_b(t_info *info);
void			ft_sort3_top_min_b(t_info *info, int mid, int bot);
void			ft_sort3_mid_min_b(t_info *info, int top, int bot);
void			ft_sort3_bot_min_b(t_info *info);
void			ft_sort_3_a(t_info *info);
void			ft_sort3_bot_min_a(t_info *info, int mid, int bot);
void			ft_sort3_mid_min_a(t_info *info, int top, int bot);
void			ft_sort3_top_min_a(t_info *info, int top, int mid);

void			sa(t_info *info);
void			sb(t_info *info);
void			ss(t_info *info);
void			pa(t_info *info);
void			pb(t_info *info);
void			rra(t_info *info);
void			rrb(t_info *info);
void			rrr(t_info *info);
void			ra(t_info *info);
void			rb(t_info *info);
void			rr(t_info *info);
#endif