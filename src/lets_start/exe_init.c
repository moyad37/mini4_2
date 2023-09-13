/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 13:49:52 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

static void	fill_args(char **tokens, int idx)
{
	int	i;
	int	args;

	i = 0;
	args = g_minishell.commands[idx].number_of_args;
	while (i < args)
	{
		g_minishell.commands[idx].args[i] = ft_strdup(tokens[i]);
		i++;
	}
}

static int	count_commands(char **tokens)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tokens[i])
	{
		if (ft_strcmp("|", tokens[i]) == 0)
			j++;
		i++;
	}
	return (j + 1);
}

void	init_commands(char **tokens, int idx)
{
	int		i;
	int		args;
	int		number_of_cmds;

	i = 0;
	if (idx == 0)
	{
		g_minishell.number_of_cmds = count_commands(tokens);
		number_of_cmds = g_minishell.number_of_cmds;
		g_minishell.commands = ft_calloc(sizeof(t_command), number_of_cmds + 1);
	}
	if (tokens[i] == NULL)
		return ;
	while (tokens[i] && ft_strcmp("|", tokens[i]) != 0)
		i++;
	if (tokens[i] && ft_strcmp("|", tokens[i]) == 0)
		i++;
	init_commands(tokens + i, idx + 1);
	args = count_args(tokens);
	g_minishell.commands[idx].number_of_args = args;
	g_minishell.commands[idx].args = ft_calloc(sizeof(char *), args + 1);
	fill_args(tokens, idx);
}

