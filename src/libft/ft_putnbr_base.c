/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_repeated_chars(char *str)
{
	size_t	len_str;
	size_t	i;
	size_t	j;

	i = 0;
	len_str = ft_strlen(str);
	if (str && len_str)
	{
		while (i < len_str)
		{
			j = (i + 1);
			while (j < len_str)
			{
				if (str[i] == str[j])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

void	ft_putnbr_base(long long nbr, char *base)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (has_repeated_chars(base))
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr < len_base)
		ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base(nbr / len_base, base);
		ft_putnbr_base(nbr % len_base, base);
	}
}
