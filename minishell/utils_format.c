/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:58:23 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/04/05 21:06:53 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_it_special(char c)
{
	if (c == ' ' || c == 9 || c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

char	*get_env_var(char *str, int len, char **env)
{
	int 	i;
	
	while (*env)
	{
		len = ft_strlen_v2(str, '=', 0);
		if (ft_strncmp(str, *env, len) == 0 && (*env)[len] == '=')
			break ;
		env++;
	}
	if (!(*env))
		return (NULL);
	return (ft_strdup(&((*env)[len + 1])));
}
