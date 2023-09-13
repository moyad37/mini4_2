/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


void	init_minishell(char **envp)
{
	g_minishell.status_code = 0;
	g_minishell.on_fork = 0;
	g_minishell.envp_list = get_envp_list(envp);
	g_minishell.envp = get_envp();
	g_minishell.builtins[0] = ft_echo;
	g_minishell.builtins[1] = ft_cd;
	g_minishell.builtins[2] = ft_pwd;
	g_minishell.builtins[3] = ft_export;
	g_minishell.builtins[4] = ft_unset;
	g_minishell.builtins[5] = ft_env;
	g_minishell.builtins[6] = ft_exit;
}