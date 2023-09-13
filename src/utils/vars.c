/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 13:36:19 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

static char	*extract_key(char *var)
{
	char	*end_var;
	char	*key;

	end_var = var;
	if (var[0] == '?')
		return (ft_strdup("?"));
	while (is_bash_char(*end_var))
		end_var++;
	key = ft_substr(var, 0, end_var - var);
	return (key);
}

void	expand_vars(char **token)
{
	int		i;
	char	*key;
	char	*value;
	char	*new_token;

	i = 0;
	new_token = ft_strdup("");
	while ((*token)[i])
	{
		if (is_valid_var(&(*token)[i]))
		{
			key = extract_key(&(*token)[i + 1]);
			value = get_key_value(g_minishell.envp_list, key);
			if ((*token)[i + 1] == '?')
				append(&new_token, value);
			else
				append(&new_token, ft_strdup(value));
			i += ft_strlen(key) + 1;
			free(key);
		}
		else
			append(&new_token, ft_strndup(&(*token)[i++], 1));
	}
	free(*token);
	*token = new_token;
}