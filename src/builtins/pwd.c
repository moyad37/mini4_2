/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_command cmd)
{
	char	*cwd;
	int		out;

	out = 1;
	handle_output(cmd, &out);
	cwd = getcwd(NULL, 0);
	if (cmd.args[0])
		ft_printf(out, "%s\n", cwd);
	ft_free(cwd);
	if (g_minishell.on_fork)
		die_child(0, 0);
	return (0);
}
