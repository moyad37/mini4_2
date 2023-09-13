/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:24:22 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:25:04 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		memory_allocated;

	if (start > ft_strlen(s))
	{
		substr = (char *) malloc(1);
		*substr = 0;
		return (substr);
	}
	else if (ft_strlen(s) > len)
		memory_allocated = len + 1;
	else
		memory_allocated = ft_strlen(s) - start + 1;
	substr = (char *) malloc(sizeof(char) * memory_allocated);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, memory_allocated);
	return (substr);
}
