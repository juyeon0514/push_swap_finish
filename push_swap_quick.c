/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:45:13 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 12:09:05 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_a(t_info *info, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		ft_sort_2(info, 1);
	}
	else if (size == 3)
	{
		ft_sort_3_a(info);
	}
	else if (size == 5)
	{
		switch_sort_5(info, size, 1);
	}
}

void	rotate_a(t_info *info, t_command_info *info2)
{
	if (info->top_a->data > info2->big_pivot)
	{
		ra(info);
		info2->ra++;
	}
	else
	{
		pb(info);
		info2->pb++;
		if (info->top_b->data > info2->small_pivot)
		{
			rb(info);
			info2->rb++;
		}
	}
}

void	back_use_ra_a(t_info *info, t_command_info *info2)
{
	int	rrr_count;
	int	tmp;

	rrr_count = info2->rb;
	tmp = info2->ra - rrr_count;
	if (info->count > 0)
	{
		while (rrr_count--)
			rrr(info);
		while (tmp--)
			rra(info);
	}
	else
	{
		while (rrr_count--)
			rrb(info);
	}
}

void	back_use_rb_a(t_info *info, t_command_info *info2)
{
	int	rrr_count;
	int	tmp;

	rrr_count = info2->ra;
	tmp = info2->rb - rrr_count;
	if (info->count > 0)
	{
		while (rrr_count--)
			rrr(info);
		while (tmp--)
			rrb(info);
	}
	else
	{
		rrr_count = info2->rb;
		while (rrr_count--)
			rrb(info);
	}
}

void	ft_a_to_b(t_info *info, int size)
{
	int				*arr;
	int				rotate;
	t_command_info	command;

	info->count++;
	if (size <= 3 || size == 5)
	{
		ft_sort_small_a(info, size);
		return ;
	}
	arr = make_stack_to_array(info, size, 1);
	info_command_init(&command);
	command.big_pivot = get_big_pivot(info, size, 1, arr);
	command.small_pivot = get_small_pivot(info, size, 1, arr);
	rotate = size;
	while (rotate--)
		rotate_a(info, &command);
	if (command.ra > command.rb)
		back_use_ra_a(info, &command);
	else
		back_use_rb_a(info, &command);
	ft_a_to_b(info, command.ra);
	ft_b_to_a(info, command.rb);
	ft_b_to_a(info, command.pb - command.rb);
}
