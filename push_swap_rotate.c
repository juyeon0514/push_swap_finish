/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:34:22 by juykang           #+#    #+#             */
/*   Updated: 2022/10/25 12:57:47 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	t_node	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->prev = NULL;
	info->bottom_a->next = tmp;
	tmp->prev = info->bottom_a;
	info->bottom_a = tmp;
	info->bottom_a->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	t_node	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->top_b->prev = NULL;
	info->bottom_b->next = tmp;
	tmp->prev = info->bottom_b;
	info->bottom_b = tmp;
	info->bottom_a->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	t_node	*tmp;

	if (info->size_b < 2 || info->size_a < 2)
		return ;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->prev = NULL;
	info->bottom_a->next = tmp;
	tmp->prev = info->bottom_a;
	info->bottom_a = tmp;
	info->bottom_a->next = NULL;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->top_b->prev = NULL;
	info->bottom_b->next = tmp;
	tmp->prev = info->bottom_b;
	info->bottom_b = tmp;
	info->bottom_a->next = NULL;
	write(1, "rr\n", 3);
}
