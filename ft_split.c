/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:32:55 by juykang           #+#    #+#             */
/*   Updated: 2022/10/25 12:57:52 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static size_t	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

static char	**ft_copy(char **strs, char const *s, char c, size_t word)
{
	size_t	i;
	size_t	j;
	size_t	size;

	j = 0;
	i = 0;
	while (j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
		{
			ft_free(strs, j);
			return (NULL);
		}
		j++;
		i += size;
	}
	strs[j] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	size_t		word;
	char		**strs;

	if (!s)
		return (NULL);
	word = ft_count_word(s, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	return (ft_copy(strs, s, c, word));
}
