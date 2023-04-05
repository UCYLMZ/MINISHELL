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

int	pass_quote(char *str, char q)
{
	int	i;

	i = 0;
	while (str[i] == q)
		i++;
	return (i);
}

char	first_quote(char *str)
{
	int		i;
	char	q;

	i = -1;
	q = 0;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			q = str[i];
			return (q);
		}
	}
	return (0);
}

int	is_it_special(char c)
{
	if (c == ' ' || c == 9 || c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

int	any_dolar(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
			return (i);
	}
	return (-1);
}
