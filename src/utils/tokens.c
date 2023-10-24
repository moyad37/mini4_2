/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/10/24 13:35:05 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

char	**get_subtokens(char *token, int idx)
{
	int		i;
	char	**subtokens;
	char	quoted;

	i = 0;
	if (*token == '\0')
		return (ft_calloc(idx + 1, sizeof(char *)));
	quoted = 0;
	if (check_zitat(token[i]))
		quoted = token[i++];
	while (token[i] && ((quoted && quoted != token[i]) || !check_zitat(token[i])))
		i++;
	if (quoted && check_zitat(token[i]))
		i++;
	subtokens = get_subtokens(token + i, idx + 1);
	subtokens[idx] = ft_substr(token, 0, i);
	return (subtokens);
}

char	*concat_subtokens(char **subtokens)
{
	int		i;
	char	*expanded_token;

	i = 0;
	expanded_token = ft_strdup("");
	while (subtokens[i])
	{
		append(&expanded_token, subtokens[i]);
		i++;
	}
	return (expanded_token);
}

void	expand_token(char **token)
{
	int		i;
	char	**subtokens;

	i = 0;
	subtokens = get_subtokens(*token, 0);
	while (subtokens[i])
	{
		if (subtokens[i][0] != SINGLE_QUOTE && ft_strchr(subtokens[i], '$'))
			expand_vars(subtokens + i);
		i++;
	}
	free(*token);
	*token = concat_subtokens(subtokens);
	if (!ft_strlen(*token))
	{
		free(*token);
		*token = NULL;
	}
	free(subtokens);
}