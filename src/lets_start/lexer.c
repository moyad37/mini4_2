/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by mmanssou          #+#    #+#             */
/*   Updated: 2023/10/24 14:05:57 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	fix_tokens(char **tokens, char set[6])
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		replace_between(tokens[i], set, SET1);
		i++;
	}
}

// static void	init_set(char set[6])
// {
// 	set[0] = 1;
// 	set[1] = 2;
// 	set[2] = 3;
// 	set[3] = 4;
// 	set[4] = 5;
// 	set[5] = 6;
// }
/*

Die Funktion `lexer` nimmt einen Eingabe-String entgegen und teilt
ihn in einzelne Tokens auf. Dabei werden bestimmte Zeichenfolgen 
im String durch vordefinierte Werte ersetzt. Das Ergebnis ist ein 
Array von Strings, das die einzelnen Tokens repräsentiert.
*/
char	**lexer(char *cmd)
{
	char	*str;
	char	**tokens;
	char	set[6];

	//init_set(set);
	set[0] = 1;
	set[1] = 2;
	set[2] = 3;
	set[3] = 4;
	set[4] = 5;
	set[5] = 6;
	str = format_cmd(cmd, 0);
	if(str == NULL)
		return (NULL);
	replace_between(str, SET1, set);
	tokens = ft_split(str);
	fix_tokens(tokens, set);
	free(str);
	
	// int i = 0;
	// while (tokens[i])
	// {
	// 	printf("tokens[%d] = %s\n", i, tokens[i]);
	// 	i++;
	// }
	
	return (tokens);
}
