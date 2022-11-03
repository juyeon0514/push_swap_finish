/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:26:01 by juykang           #+#    #+#             */
/*   Updated: 2022/11/03 11:46:46 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_ps(const char *str)
{
	int			i;
	long long	num;
	long long	result;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	result = num * sign;
	if ((result < -2147483648 || result > 2147483647))
		ft_error(-1);
	return (result);
}

int	check_str_size(int argc, char **argv)
{
	int		index;
	int		index2;
	int		size;
	char	**split_str;

	index = 0;
	size = 0;
	while (index < argc)
	{
		index2 = 0;
		while (argv[index][index2])
		{
			if (!((argv[index][index2] >= 9 && argv[index][index2] <= 13) \
			|| (argv[index][index2] == 32)))
				break ;
			index2++;
		}
		if (argv[index][index2] == '\0')
			ft_error(-1);
		split_str = ft_split(argv[index], ' ');
		size += check_size_split_str(split_str);
		ft_free_str(split_str);
		index++;
	}
	return (size - 1);
}

int	*make_av_to_array(int argc, char **argv, int size)
{
	int		argc_index;
	int		arr_index;
	int		*new_array;
	char	**split_str;

	argc_index = 1;
	arr_index = 0;
	new_array = (int *)malloc(sizeof(int) * size);
	if (!new_array)
		ft_error(-1);
	while (argc_index < argc)
	{
		split_str = ft_split(argv[argc_index], ' ');
		make_str_to_array(new_array, &arr_index, split_str);
		ft_free_str(split_str);
		argc_index++;
	}
	return (new_array);
}

void	make_arr_to_stack(t_info *info, int *array, int size)
{
	t_node		*new_node;
	int			index;

	index = 0;
	while (index < size)
	{
		new_node = stack_init();
		info->size_a++;
		info->bottom_a->data = array[index];
		info->bottom_a->next = new_node;
		new_node->prev = info->bottom_a;
		info->bottom_a = new_node;
		info->pre_pivot = 0;
		index++;
	}
	info->bottom_a = info->bottom_a->prev;
	free(new_node);
}

void	array_sort(int *array, int size, int index, t_info *info)
{
	int	j;
	int	check;
	int	tmp;

	check = 0;
	while (index < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				check++;
			}
			j++;
		}
		if (array[index] == array[index + 1])
			ft_error(-1);
		index++;
	}
	if (check == 0 && info->count == 0)
		ft_error(0);
}
