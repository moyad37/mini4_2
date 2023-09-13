/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

void	close_fds(void)
{
	int	i;
	int	commands_size;

	i = 0;
	commands_size = g_minishell.number_of_cmds;
	if (g_minishell.commands == NULL)
		return ;
	while (i < commands_size)
	{
		if (g_minishell.commands[i].input_fd != 0)
			close(g_minishell.commands[i].input_fd);
		if (g_minishell.commands[i].output_fd != 1)
			close(g_minishell.commands[i].output_fd);
		i++;
	}
}

void	ft_free_commands(void)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.number_of_cmds;
	close_fds();
	while (i < args)
	{
		ft_free_matrix((void **)g_minishell.commands[i].args);
		ft_free((void *)g_minishell.commands[i].bin_path);
		i++;
	}
	free(g_minishell.commands);
	g_minishell.commands = NULL;
}
