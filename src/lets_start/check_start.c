/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	space_duplicate_metachars(char *str, int pos)
{
	int	i;

	i = 0;
	if (pos != 0 && *(str - 1) != ' ')
	{
		ft_memmove(str + 1, str, ft_strlen(str));
		str[0] = ' ';
		i++;
		if (str[3] != ' ')
		{
			ft_memmove(str + 4, str + 3, ft_strlen(str));
			str[3] = ' ';
			i++;
		}
	}
	else if (str[2] != ' ')
	{
		ft_memmove(str + 3, str + 2, ft_strlen(str));
		str[2] = ' ';
		i++;
	}
	return (i);
}


char	**pipeline_validation(char *cmd)
{
	char	**tokens;

	tokens = NULL;
	if (cmd == NULL)
		die();
	if (cmd[0] == '\0')
		ft_free(cmd);
	else
	{
		add_history(cmd);
		tokens = lexer(cmd);
		ft_free(cmd);
		if (parser(&tokens) == 1 || *tokens == NULL)
		{
			ft_free_matrix((void **)tokens);
			return (NULL);
		}
	}
	return (tokens);
}