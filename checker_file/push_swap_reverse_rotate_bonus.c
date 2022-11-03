/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotate_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:02:43 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 15:02:51 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_info *info)
{
	t_node	*tmp;

	if (info->size_a < 2)
	{
		return ;
	}
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_node	*tmp;

	if (info->size_b < 2)
	{
		return ;
	}
	tmp = info->bottom_b;
	info->bottom_b = info->bottom_b->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	t_node	*tmp;

	if (info->size_b < 2 || info->size_a < 2)
	{
		return ;
	}
	tmp = info->bottom_a;
	info->bottom_a = info->bottom_a->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = tmp;
	tmp->next = info->top_a;
	info->top_a = tmp;
	info->top_a->prev = NULL;
	tmp = info->bottom_b;
	info->bottom_b = info->bottom_b->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = tmp;
	tmp->next = info->top_b;
	info->top_b = tmp;
	info->top_b->prev = NULL;
	write(1, "rrr\n", 4);
}
