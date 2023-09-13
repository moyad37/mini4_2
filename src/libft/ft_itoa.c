/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigits(long int n);
static void	get_result(long int n, char *str, int *i, int *bytes);

static void	get_result(long int n, char *str, int *i, int *bytes)
{
	if (*bytes == 2)
		*(str + 0) = '-';
	while (*i >= 0)
	{
		if (*bytes == 2 && (*i) == 0)
			break ;
		*(str + *i) = (n % 10) + '0';
		n -= n % 10;
		n /= 10;
		(*i)--;
	}
}

static int	countdigits(long int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	long_n;
	int			digits;
	int			i;
	int			bytes_to_alloc;
	char		*str;

	long_n = n;
	if (n < 0)
	{
		bytes_to_alloc = 2;
		long_n = long_n * -1;
	}
	else
		bytes_to_alloc = 1;
	digits = countdigits(long_n);
	str = malloc(digits + bytes_to_alloc);
	if (!str)
		return (NULL);
	i = digits + bytes_to_alloc - 1;
	*(str + i) = '\0';
	i--;
	get_result(long_n, str, &i, &bytes_to_alloc);
	return (str);
}
