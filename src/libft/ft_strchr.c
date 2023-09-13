/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*first_occurence;

	i = 0;
	first_occurence = 0;
	if (!s)
		return (NULL);
	while (*(s + i))
	{
		if (*(s + i) == (unsigned char) c)
		{
			first_occurence = (s + i);
			return ((char *) first_occurence);
		}
		i++;
	}
	if (c == 0)
		first_occurence = (s + ft_strlen(s));
	return ((char *) first_occurence);
}
