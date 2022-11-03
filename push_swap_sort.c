/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:17:20 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 02:30:17 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mid2_value(t_info *info, int size, int flag)
{
	int		*arr;

	arr = make_stack_to_array(info, size, flag);
	return (arr[1]);
}

void	ft_sort_4(t_info *info, int size)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid2_value(info, 4, 1);
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
		if (push == 1)
			break ;
	}
	while (rotate--)
		rrb(info);
}

void	ft_sort_2(t_info *info, int flag)
{
	if (flag == 1)
	{
		if (info->top_a->data > info->top_a->next->data)
			sa(info);
	}
	else
	{
		if (info->top_b->data < info->top_b->next->data)
			sb(info);
		pa(info);
		pa(info);
	}
}

void	ft_sort(t_info *info)
{
	if (info->size_a == 2)
	{
		if (info->top_a->data > info->top_a->next->data)
			sa(info);
	}
	else if (info->size_a == 3)
	{
		ft_sort_3_a(info);
	}
	else if (info->size_a == 4)
	{
		ft_sort_4(info, 4);
		ft_sort_3_a(info);
		pa(info);
	}
	else if (info->size_a == 5)
	{
		ft_sort_5(info);
	}
	else
	{
		ft_a_to_b(info, info->size_a);
	}
}
