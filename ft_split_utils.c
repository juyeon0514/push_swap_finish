/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_uitls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:59:35 by juykang           #+#    #+#             */
/*   Updated: 2022/10/25 13:01:11 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*temp;

	len = ft_strlen(s1);
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*temp;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (ft_strdup(""));
	if (s_len - start < len)
		len = s_len - start;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		temp[i] = s[start + i];
		if (!temp)
			return (NULL);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
