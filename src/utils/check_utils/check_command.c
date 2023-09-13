/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_output_redirect(char *redirect)
{
	if (ft_strcmp(redirect, ">") == 0 || ft_strcmp(redirect, ">>") == 0)
		return (1);
	return (0);
}

int	is_input_redirect(char *redirect)
{
	if (ft_strcmp(redirect, "<") == 0 || ft_strcmp(redirect, "<<") == 0)
		return (1);
	return (0);
}

int	is_redirect(char *str)
{
	if (ft_strcmp(">", str) == 0 || ft_strcmp(">>", str) == 0 \
		|| ft_strcmp("<", str) == 0 || ft_strcmp("<<", str) == 0)
		return (1);
	return (0);
}
