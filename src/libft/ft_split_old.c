/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_old.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

char	**ft_split_old(const char *str, char c)
{
	int		i;
	char	**lst;
	size_t	curr_word_len;

	i = 0;
	if (!str)
		return (0);
	lst = (char **)ft_calloc(sizeof(char *), count_words(str, c) + 1);
	if (!lst)
		return (0);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				curr_word_len = ft_strlen((char *)str);
			else
				curr_word_len = ft_strchr(str, c) - str;
			lst[i++] = ft_substr(str, 0, curr_word_len);
			str += curr_word_len;
		}
	}
	return (lst);
}
