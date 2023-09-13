/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_env(void)
{
	ft_free_matrix((void **)g_minishell.envp);
	g_minishell.envp = get_envp();
}

void	update_number_of_args(void)
{
	int			i;
	int			size;
	t_command	*cmd;

	i = 0;
	size = g_minishell.number_of_cmds;
	while (i < size)
	{
		cmd = &g_minishell.commands[i];
		cmd->number_of_args = count_args(cmd->args);
		i++;
	}
}
