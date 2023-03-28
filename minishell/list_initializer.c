/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:16:23 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/03/28 05:45:57 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	characters_check(char *trimmed)
{
	char	*set;
	int		i;

	set = ">|<";
	while (*trimmed)
	{
		i = -1;
		while (set[++i])
		{
			if (set[i] == *trimmed)
				return (i + 1);
		}
		trimmed++;
	}
	return (0);
}

char	*cmd_reducer(char *source)
{
	char	**splitted;
	char	*result;
	int		i;

	result = NULL;
	if (*source == 34 || *source == 39)
	{
		printf("source: %s\n", source);
		splitted = ft_split(source, g_arg.quote_flag);
		i = -1;
		while (splitted[++i] && !characters_check(splitted[i]))
			result = ft_strjoin_v2(result, splitted[i]);
		while (splitted[i])
		{
			
		}
		printf("%s\n", result);
		printf("splitted:%s\n", splitted[i]);
	}
}

int	list_init(void)
{
	int	i;

	ft_lstclear_v2(g_arg.list);
	i = -1;
	while (g_arg.args[++i])
		cmd_reducer(g_arg.args[i]);
}
