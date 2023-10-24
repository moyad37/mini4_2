/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/10/24 13:51:25 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_bash_char(char c)
{
	if (!ft_isalpha(c) && !ft_isdigit(c) && c != '_')
		return (0);
	return (1);
}

int	check_pipe(char c)
{
	if (ft_strchr(">|<", c))
		return (1);
	return (0);
}

int	is_dir(const char *path)
{
	struct stat	file_stat;

	if (!path)
		return (0);
	file_stat.st_mode = 0;
	stat(path, &file_stat);
	return (S_ISDIR(file_stat.st_mode));
}

int	check_zitat(char c)
{
	if (c == SINGLE_QUOTE || c == DOUBLE_QUOTE)
		return (1);
	return (0);
}

int	is_valid_var(char *str)
{
	if (str[0] == '$' && (ft_isalpha(str[1]) || str[1] == '_' || str[1] == '?'))
		return (1);
	return (0);
}

