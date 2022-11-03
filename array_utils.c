/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:26:28 by juykang           #+#    #+#             */
/*   Updated: 2022/10/26 14:40:53 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_size_split_str(char **split_str)
{
	int	index;

	index = 0;
	while (split_str[index])
	{
		index++;
	}
	return (index);
}

void	ft_free_str(char **array)
{
	int	index;

	index = 0;
	while (array[index])
	{
		free(array[index]);
		index++;
	}
	free(array);
}

void	make_str_to_array(int *array, int *arr_idx, char **str)
{
	int	number;
	int	index;

	index = 0;
	while (str[index])
	{
		number = ft_atoi_ps(str[index]);
		array[*arr_idx] = number;
		(*arr_idx)++;
		index++;
	}
}
