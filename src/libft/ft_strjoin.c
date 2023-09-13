/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dest, const char *src);

static void	ft_strcpy(char *dest, const char *src)
{
	int		i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	if (!src)
		return ;
	while (*(src + i))
	{
		*(dest + dest_len + i) = *(src + i);
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*finalstr;

	finalstr = ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!finalstr)
		return (NULL);
	ft_strcpy(finalstr, s1);
	ft_strcpy(finalstr, s2);
	*(finalstr + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	return (finalstr);
}
