/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *) big);
	while (*(big + i) && i < len)
	{
		if (*(big + i) == *(little + 0))
		{
			j = 0;
			while (*(big + i + j) == *(little + j) && \
					(*(big + i + j) && *(little + j)))
			{
				if (i + j >= len)
					return (NULL);
				j++;
			}
			if (j == ft_strlen(little))
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}
