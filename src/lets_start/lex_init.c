/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:08:00 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

static int	count_metachars(char *cmd)
{
	int		i;
	int		amount_of_metachars;

	i = 0;
	amount_of_metachars = 0;
	while (cmd[i])
	{
		if (is_meta_char(cmd[i]))
			amount_of_metachars++;
		i++;
	}
	return (amount_of_metachars);
}

char	*init_human_readable_cmd(char *cmd)
{
	char	*new_cmd;
	int		mem_to_alloc;
	int		max_spaces_to_insert;

	max_spaces_to_insert = count_metachars(cmd) * 2;
	mem_to_alloc = max_spaces_to_insert + ft_strlen(cmd) + 2;
	new_cmd = malloc(sizeof(char) * mem_to_alloc);
	ft_bzero(new_cmd, mem_to_alloc);
	ft_strlcpy(new_cmd, cmd, mem_to_alloc);
	return (new_cmd);
}