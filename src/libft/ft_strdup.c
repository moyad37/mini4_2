/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len_s;
	int		i;
	char	*dup;

	i = 0;
	len_s = ft_strlen(s);
	dup = (char *) malloc((len_s * sizeof(char)) + 1);
	if (s)
	{
		while (*(s + i))
		{
			*(dup + i) = *(s + i);
			i++;
		}
	}
	*(dup + i) = '\0';
	return (dup);
}
