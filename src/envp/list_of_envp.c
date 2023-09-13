/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_of_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:59 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*get_envp_list(char **envp)
{
	int		i;
	char	**key_and_value;
	t_node	*envp_list;
	t_node	*new_node;

	i = 0;
	envp_list = NULL;
	while (envp[i] != NULL)
	{
		key_and_value = get_matrix_with_key_value(envp[i]);
		new_node = ft_lstnew(key_and_value[0], key_and_value[1], envp[i]);
		ft_free_matrix((void **)key_and_value);
		ft_lstadd_back(&envp_list, new_node);
		i++;
	}
	return (envp_list);
}