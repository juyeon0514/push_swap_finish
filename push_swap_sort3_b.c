/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort3_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:18:08 by juykang           #+#    #+#             */
/*   Updated: 2022/11/02 23:07:22 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3_top_min_b(t_info *info, int mid, int bot)
{
	int	max;

	max = ft_max(mid, bot);
	if (info->size_b == 3)
	{
		rb(info);
		if (info->top_b->next->data == max)
			sb(info);
	}
	else
	{
		sb(info);
		rb(info);
		sb(info);
		rrb(info);
		if (info->top_b->next->data == max)
			sb(info);
	}
}

void	ft_sort3_mid_min_b(t_info *info, int top, int bot)
{
	int			max;

	max = ft_max(top, bot);
	if (info->size_b == 3)
	{
		rrb(info);
		if (info->top_b->next->data == max)
			sb(info);
	}
	else
	{
		rb(info);
		sb(info);
		rrb(info);
		if (info->top_b->next->data == max)
			sb(info);
	}
}

void	ft_sort3_bot_min_b(t_info *info)
{
	sb(info);
}

void	ft_sort_3_b(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->top_b->data;
	mid = info->top_b->next->data;
	bot = info->top_b->next->next->data;
	if (top < mid && top < bot)
		ft_sort3_top_min_b(info, mid, bot);
	else if (mid < top && mid < bot)
		ft_sort3_mid_min_b(info, top, bot);
	else if (bot < top && bot < mid && top < mid)
		ft_sort3_bot_min_b(info);
	pa(info);
	pa(info);
	pa(info);
}
