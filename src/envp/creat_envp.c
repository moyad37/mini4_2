/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	amount_of_valid_keys(t_node **envp)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = *envp;
	while (tmp)
	{
		if (tmp->value && tmp->env_line)
			size++;
		tmp = tmp->next;
	}
	return (size);
}

char	**get_envp(void)
{
	int		i;
	int		size;
	char	**envp;
	t_node	*tmp;

	i = 0;
	tmp = g_minishell.envp_list;
	size = amount_of_valid_keys(&g_minishell.envp_list);
	envp = ft_calloc(sizeof(char *), size + 1);
	while (tmp)
	{
		if (tmp->value && tmp->env_line)
		{
			envp[i] = ft_strdup(tmp->env_line);
			i++;
		}
		tmp = tmp->next;
	}
	return (envp);
}
