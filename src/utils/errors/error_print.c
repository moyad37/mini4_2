/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/10/02 15:16:16 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../includes/minishell.h"

void	fill_status_code(t_command cmd)
{
	if (g_minishell.status_code == 0)
		return ;
	if (is_dir(cmd.args[0]) && access(cmd.args[0], F_OK | X_OK) == 0 \
			&& ft_strchr(cmd.args[0], 47))
		g_minishell.status_code = 126;
	else if (ft_strchr(cmd.args[0], 47) && cmd.bin_path == NULL \
			&& access(cmd.args[0], F_OK) == -1)
		g_minishell.status_code = 127;
	else if (cmd.bin_path == NULL && cmd.args[0] \
			&& access(cmd.args[0], X_OK) == -1 && ft_strchr(cmd.args[0], 47))
		g_minishell.status_code = 126;
	else if (cmd.bin_path == NULL && cmd.args[0])
		g_minishell.status_code = 127;
}

void	print_curr_err(t_command cmd)
{
	if (is_dir(cmd.args[0]) && access(cmd.args[0], F_OK | X_OK) == 0 \
			&& ft_strchr(cmd.args[0], 47))
		p_fd(STDERR_FILENO, "bash: %s: Is a directory\n", cmd.args[0]);
	else if (ft_strchr(cmd.args[0], 47) && cmd.bin_path == NULL \
			&& access(cmd.args[0], F_OK) == -1)
		p_fd(2, "bash: %s: No such file or directory\n", cmd.args[0]);
	else if (cmd.bin_path == NULL && cmd.args[0] \
			&& access(cmd.args[0], X_OK) == -1 && ft_strchr(cmd.args[0], 47))
		p_fd(STDERR_FILENO, "bash: %s: Permission denied\n", cmd.args[0]);
	else if (cmd.bin_path == NULL && cmd.args[0])
		p_fd(STDERR_FILENO, "%s: command not found\n", cmd.args[0]);
	fill_status_code(cmd);
}
