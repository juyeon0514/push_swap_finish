/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:49:00 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 13:49:07 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include "push_swap.h"

int	ft_error(int flag)
{
	if (flag == -1)
	{
		write(2, "Error\n", 6);
	}
	exit(1);
	return (-1);
}

t_node	*stack_init(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_info	*ft_info_init(void)
{
	t_node		*stack_a;
	t_info		*new_info;

	new_info = NULL;
	new_info = (t_info *)malloc(sizeof(t_info));
	stack_a = stack_init();
	new_info->array = NULL;
	new_info->size_a = 0;
	new_info->size_b = 0;
	new_info->count = 0;
	new_info->top_a = stack_a;
	new_info->bottom_a = stack_a;
	return (new_info);
}

int	main(int argc, char **argv)
{
	int			array_size;
	int			*num_array;
	t_info		*info;

	if (argc < 2)
		ft_error(-1);
	array_size = 0;
	info = ft_info_init();
	array_size = check_str_size(argc, argv);
	num_array = make_av_to_array(argc, argv, array_size);
	make_arr_to_stack(info, num_array, array_size);
	array_sort(num_array, array_size, 0, info);
	info->array = num_array;
	ft_sort(info);
	return (0);
}
