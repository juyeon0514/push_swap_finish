/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:17:20 by juykang           #+#    #+#             */
/*   Updated: 2022/11/04 17:04:03 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ft_sort_4(t_info *info, int size)
{
	int	push;
	int	rotate;
	int	*arr;

	push = 0;
	rotate = 0;
	arr = make_stack_to_array(info, size, 1);
	while (size--)
	{
		if (info->top_a->data < arr[1])
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
	free(arr);
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
