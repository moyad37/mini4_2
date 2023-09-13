/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou  <mmanssou@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/09/13 13:54:40 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/minishell.h"

static int	is_empty_quote(char *str)
{
	if (*str == str[1])
		return (1);
	return (0);
}

static void	erase_external_quotes(char *str)
{
	int	last_pos;
	int	str_len;

	str_len = ft_strlen(str);
	ft_memmove(str, str + 1, str_len);
	last_pos = str_len - 2;
	ft_memset(str + last_pos, 0, 1);
}

void	clear_subtokens(char **subtokens)
{
	int	i;

	i = 0;
	while (subtokens[i])
	{
		if (is_quote(*subtokens[i]) && is_empty_quote(subtokens[i]))
			ft_memset(subtokens[i], 0, 2);
		else if (is_quote(*subtokens[i]))
			erase_external_quotes(subtokens[i]);
		i++;
	}
}