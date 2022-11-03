/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:39:02 by juykang           #+#    #+#             */
/*   Updated: 2022/11/02 23:08:18 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mid_value(t_info *info, int size, int flag)
{
	int		*arr;

	arr = make_stack_to_array(info, size, flag);
	return (arr[2]);
}

void	ft_sort_5_a(t_info *info, int size)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value(info, 5, 1);
	while (size--)
	{
		if (info->top_a->data < mid)
		{
			pb(info);
			push++;
		}
		else
		{
			ra(info);
			rotate++;
		}
		if (push == 2)
			break ;
	}
	while (rotate--)
		rra(info);
}

void	ft_sort_5_b(t_info *info, int size)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value(info, 5, 2);
	while (size--)
	{
		if (info->top_b->data >= mid)
		{
			pa(info);
			push++;
		}
		else
		{
			rb(info);
			rotate++;
		}
		if (push == 3)
			break ;
	}
	while (rotate--)
		rrb(info);
}

void	switch_sort_5(t_info *info, int size, int flag)
{
	if (flag == 1)
		ft_sort_5_a(info, size);
	else
		ft_sort_5_b(info, size);
	ft_sort_3_a(info);
	ft_sort_2(info, 2);
}

void	ft_sort_5(t_info *info)
{
	int	pb_check;
	int	mid;

	pb_check = 0;
	mid = info->array[2];
	while (1)
	{
		if (info->top_a->data < mid)
		{
			pb(info);
			pb_check++;
		}
		else
			ra(info);
		if (pb_check == 2)
			break ;
	}
	ft_sort_3_a(info);
	ft_sort_2(info, 2);
}
