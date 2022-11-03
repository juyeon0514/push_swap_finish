/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:07:14 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 01:08:31 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_sort_b(t_info *info, int size)
{
	if (size == 1)
		pa(info);
	if (size == 2)
	{
		ft_sort_2(info, 2);
	}
	else if (size == 3)
	{
		ft_sort_3_b(info);
	}
	else if (size == 5)
	{
		switch_sort_5(info, size, 2);
	}
}

void	rotate_b(t_info *info, t_command_info *info2)
{
	if (info->top_b->data <= info2->small_pivot)
	{
		rb(info);
		info2->rb++;
	}
	else
	{
		pa(info);
		info2->pa++;
		if (info->top_a->data <= info2->big_pivot)
		{
			ra(info);
			info2->ra++;
		}
	}
}

void	back_use_ra_b(t_info *info, t_command_info *info2)
{
	int	rrr_count;
	int	tmp;

	rrr_count = info2->rb;
	tmp = info2->ra - rrr_count;
	while (rrr_count--)
		rrr(info);
	while (tmp--)
		rra(info);
}

void	back_use_rb_b(t_info *info, t_command_info *info2)
{
	int	rrr_count;
	int	tmp;

	rrr_count = info2->ra;
	tmp = info2->rb - rrr_count;
	while (rrr_count--)
		rrr(info);
	while (tmp--)
		rrb(info);
}

void	ft_b_to_a(t_info *info, int size)
{
	int				check;
	int				*arr2;
	t_command_info	command;

	info->count++;
	if (size <= 3 || size == 5)
	{
		ft_small_sort_b(info, size);
		return ;
	}
	arr2 = make_stack_to_array(info, size, 2);
	init_info_command(&command);
	command.big_pivot = get_big_pivot(info, size, 2, arr2);
	command.small_pivot = get_small_pivot(info, size, 2, arr2);
	check = size;
	while (check--)
		rotate_b(info, &command);
	ft_a_to_b(info, command.pa - command.ra);
	if (command.ra > command.rb)
		back_use_ra_b(info, &command);
	else
		back_use_rb_b(info, &command);
	ft_a_to_b(info, command.ra);
	ft_b_to_a(info, command.rb);
}
