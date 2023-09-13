/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	put_spaces(char *str, int pos)
{
	int	i;

	i = 0;
	if (pos != 0 && *(str - 1) != ' ')
	{
		ft_memmove(str + 1, str, ft_strlen(str));
		str[0] = ' ';
		i++;
		if (str[2] != ' ')
		{
			ft_memmove(str + 3, str + 2, ft_strlen(str));
			str[2] = ' ';
			i++;
		}
	}
	else if (str[1] != ' ')
	{
		ft_memmove(str + 2, str + 1, ft_strlen(str));
		str[1] = ' ';
		i++;
	}
	return (i);
}

static int	is_duplicate_meta_char(char *str)
{
	if (*str != '|' && (is_meta_char(*str) && *str == *(str + 1)))
		return (1);
	return (0);
}

static void	put_space_if_needed(char *cmd, int *i)
{
	if (is_duplicate_meta_char(&cmd[*i]))
		*i += space_duplicate_metachars(&cmd[*i], *i) + 2;
	else if (is_meta_char(cmd[*i]))
		*i += put_spaces(&cmd[*i], *i) + 1;
}

char	*human_readable_cmd(char *cmd)
{
	int		i;
	char	quoted;
	char	*new_cmd;

	i = 0;
	quoted = '\0';
	new_cmd = init_human_readable_cmd(cmd);
	while (new_cmd[i])
	{
		if (is_quote(new_cmd[i]) && quoted == '\0')
		{
			quoted = new_cmd[i];
			i++;
		}
		else if (quoted == '\0' && is_meta_char(new_cmd[i]))
			put_space_if_needed(new_cmd, &i);
		else if (quoted == new_cmd[i])
		{
			quoted = '\0';
			i++;
		}
		else
			i++;
	}
	return (new_cmd);
}