/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:14:56 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 12:08:20 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_stack_to_array(t_info *info, int size, int flag)
{
	t_node	*tmp;
	int		index;
	int		*stack_array;

	index = -1;
	if (flag == 1)
		tmp = info->top_a;
	if (flag == 2)
		tmp = info->top_b;
	stack_array = (int *)malloc(sizeof(int) * size);
	if (!stack_array)
		ft_error(-1);
	while (++index < size)
	{
		stack_array[index] = tmp->data;
		tmp = tmp->next;
	}
	array_sort(stack_array, size, 0, info);
	info->array = stack_array;
	return (stack_array);
}

int	get_big_pivot(t_info *info, int size, int flag, int *arr)
{
	int	prepivot;
	int	b_pivot;
	int	*array_num;

	array_num = arr;
	prepivot = info->pre_pivot;
	if (flag == 1)
		b_pivot = array_num[((size * 2) / 3)];
	if (flag == 2)
		b_pivot = array_num[((size * 2) / 3)];
	if (size == 4)
		b_pivot = array_num[3];
	if (size == 6)
		b_pivot = array_num[3];
	info->pre_pivot = b_pivot;
	return (b_pivot);
}

int	get_small_pivot(t_info *info, int size, int flag, int *arr)
{
	int	prepivot;
	int	s_pivot;
	int	*array_num;

	array_num = arr;
	prepivot = info->pre_pivot;
	if (flag == 1)
		s_pivot = array_num[(size / 3) + 1];
	if (flag == 2)
		s_pivot = array_num[(size / 3) + 1];
	if (size == 4)
		s_pivot = array_num[1];
	if (size == 6)
		s_pivot = array_num[1];
	return (s_pivot);
}

void	info_command_init(t_command_info *info2)
{
	info2->pa = 0;
	info2->pb = 0;
	info2->ra = 0;
	info2->rb = 0;
	info2->big_pivot = 0;
	info2->small_pivot = 0;
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
