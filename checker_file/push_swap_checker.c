/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:40:07 by juykang           #+#    #+#             */
/*   Updated: 2022/11/05 14:52:28 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	i = 0;
	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while ((temp_s1[i] || temp_s2[i]) && i < n)
	{
		if (temp_s1[i] != temp_s2[i])
		{
			return (temp_s1[i] - temp_s2[i]);
		}
		i++;
	}
	return (1);
}

int	check_sort(t_info *info)
{
	t_node	*tmp;

	tmp = info->top_a;
	if (info->size_a == 1)
		return (1);
	while (!tmp)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	do_operation(t_info *info, char *str)
{
	if (ft_strncmp("sa\n", str, 3))
		sa(info);
	else if (ft_strncmp("sb\n", str, 3))
		sb(info);
	else if (ft_strncmp("ss\n", str, 3))
		ss(info);
	else if (ft_strncmp("ra\n", str, 3))
		ra(info);
	else if (ft_strncmp("rb\n", str, 3))
		rb(info);
	else if (ft_strncmp("rr\n", str, 3))
		rr(info);
	else if (ft_strncmp("pa\n", str, 3))
		pa(info);
	else if (ft_strncmp("pb\n", str, 3))
		pb(info);
	else if (ft_strncmp("rra\n", str, 4))
		rra(info);
	else if (ft_strncmp("rrb\n", str, 4))
		rrb(info);
	else if (ft_strncmp("rrr\n", str, 4))
		rrr(info);
	else
		ft_error(-1);
}

void	ft_checker(t_info *info)
{
	char	*buff;

	while (1)
	{
		buff = get_next_line(0);
		if (!buff)
			break ;
		do_operation(info, buff);
		free(buff);
	}
	free(buff);
	if (check_sort && !info->top_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
