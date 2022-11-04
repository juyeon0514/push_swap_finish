/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort3_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:04:12 by juykang           #+#    #+#             */
/*   Updated: 2022/11/04 17:16:52 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort3_top_min_a(t_info *info, int mid, int bot)
{
	int	max;

	max = ft_max(mid, bot);
	if (info->size_a == 3)
	{
		if (info->top_a->next->data == max)
		{
			rra(info);
			sa(info);
		}
	}
	else
	{
		if (info->top_a->next->data == max)
		{
			ra(info);
			sa(info);
			rra(info);
		}
	}
}

static void	ft_sort3_mid_min_a(t_info *info, int top, int bot)
{
	int	max;

	max = ft_max(top, bot);
	if (info->size_a == 3)
	{
		if (info->bottom_a->data == max)
			sa(info);
		else
			ra(info);
	}
	else
	{
		sa(info);
		if (info->top_a->next->data == max)
		{
			ra(info);
			sa(info);
			rra(info);
		}
	}
}

static void	ft_sort3_bot_min_a(t_info *info, int top, int mid)
{
	int	max;

	max = ft_max(top, mid);
	if (info->size_a == 3)
	{
		if (info->top_a->data == max)
			sa(info);
		rra(info);
	}
	else
	{
		if (info->top_a->data == max)
			sa(info);
		ra(info);
		sa(info);
		rra(info);
		sa(info);
	}
}

void	ft_sort_3_a(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->top_a->data;
	mid = info->top_a->next->data;
	bot = info->top_a->next->next->data;
	if (top < mid && top < bot)
		ft_sort3_top_min_a(info, mid, bot);
	else if (mid < top && mid < bot)
		ft_sort3_mid_min_a(info, top, bot);
	else if (bot < top && bot < mid)
		ft_sort3_bot_min_a(info, top, mid);
}
