/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_matrix_with_key_value(char *env_variable)
{
	long int	adresses_diff;
	char		**key_and_value;
	char		*equal_occurence;

	equal_occurence = ft_strchr(env_variable, '=');
	adresses_diff = ft_labs(env_variable - equal_occurence);
	key_and_value = ft_calloc(sizeof(char *), 3);
	key_and_value[0] = ft_calloc(sizeof(char), adresses_diff + 1);
	ft_strlcpy(key_and_value[0], env_variable, adresses_diff + 1);
	if (equal_occurence)
		key_and_value[1] = ft_strdup(++equal_occurence);
	else
		key_and_value[1] = NULL;
	return (key_and_value);
}

void	ft_print_matrix_fd(char **matrix, int fd)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_putstr_fd(matrix[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
}
