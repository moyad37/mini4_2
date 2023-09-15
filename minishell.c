/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/15 13:57:35 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include "./src/libft/libft.h"

t_minishell	g_minishell;

static void	print_possible_errors(void)
{
	int			i;
	int			size;
	t_command	cmd;

	i = 0;
	size = g_minishell.number_of_cmds;
	while (i < size && get_builtin_pos(g_minishell.commands[i].args[0]) == -1)
	{
		cmd = g_minishell.commands[i];
		print_curr_err(cmd);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	char	**tokens;

	if (argc != 1 && !argv)
		return (0);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	init_minishell(envp);
	while (1)
	{
		cmd = readline("$ ");
		tokens = pipeline_validation(cmd);
		if (tokens)
		{
			executor(tokens);
			print_possible_errors();
			ft_free_commands();
		}
	}
	return (0);
}
