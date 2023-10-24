/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endProChild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/10/20 15:14:18 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_fds_in_child(void)
{
	int			i;
	int			size;
	t_command	cmd;

	i = 0;
	size = g_minishell.number_of_cmds;
	while (i < size)
	{
		cmd = g_minishell.commands[i];
		if (cmd.input_fd != 0)
			close(cmd.input_fd);
		if (cmd.output_fd != 1)
			close(cmd.output_fd);
		if (cmd.pipe[0] != 0)
			close(cmd.pipe[0]);
		if (cmd.pipe[1] != 0)
			close(cmd.pipe[1]);
		i++;
	}
}

void	end_pro_child(int heredoc, int exit_code)
{
	if (heredoc)
		close(g_minishell.heredoc.fd);
	else
		close_fds_in_child();
	ft_free_commands();
	ft_free_matrix((void **)g_minishell.envp);
	ft_free_list(&g_minishell.envp_list);
	rl_clear_history();
	exit(exit_code);
}
