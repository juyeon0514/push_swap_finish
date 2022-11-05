/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:50:03 by juykang           #+#    #+#             */
/*   Updated: 2022/11/05 14:56:17 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	check_arg(const char *str)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	if (str[index] == '-' || str[index] == '+')
		index++;
	if (str[index] == '0')
	{
		len++;
		index++;
	}
	while (str[index] == '0')
		index++;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
		len++;
	}
	if (len < 0 || len > 11)
		return (0);
	return (1);
}
