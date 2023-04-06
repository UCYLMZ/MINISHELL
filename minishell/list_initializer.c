/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:58:05 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/04/05 21:08:34 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*dolar_handler(char *str, char q)
{
	int		i;
	int		j;
	char	*result;
	char	*env;

	if (q == 39)
		return (str);
	result = NULL;
	i = -1;
	j = 0;
	while (str[++i])
	{
		//printf("str[i]: %c\n", str[i]);
		if (str[i] == '$')
		{
			env = NULL;
			result = ft_strjoin_v3(result, ft_strdup_v2(str, j, i));
			i++;
			j = i;
			while (ft_isalnum(str[i]))
				i++;
			env = get_env_var(&str[j], i - j, g_arg.envp);
			//printf("env: %s\n", env);
			if (env)
				result = ft_strjoin_v3(result, env);
			printf("res: %s\n", result);
		}
	}
	//get_env_var(str, 0, g_arg.envp);
	if (result)
		return (result);
	return (str);
}

char	*handle_regular(char *str, int *index)
{
	int		i;
	char	*result;

	i = *index;
	while (str[i] && !is_it_special(str[i]) && str[i] != 34 && str[i] != 39)
		i++;
	result = ft_strdup_v2(str, *index, i);
	*index = i;
	return (result);
}

void	handle_others(char *str, int *index, char q)
{
	int		i;
	int		flag;
	char	*result;

	result = NULL;
	i = *index;
	while (str[i] && !is_it_special(str[i]))
	{
		if (str[i] == 34 || str[i] == 39)
		{
			i++;
			result = ft_strjoin_v3(result, dolar_handler
					(ft_strdup_v3(str, &i, str[i - 1]), str[i - 1]));
		}
		else
			result = ft_strjoin_v3(result,
					dolar_handler(handle_regular(str, &i), 0));
	}
	ft_lstadd_back_v2(&g_arg.list, ft_lstnew_v2(result, 'o'));
	*index = i;
}

void	special_handler(char *str, int *index, char q)
{
	int		backup;
	int		i;
	char	*result;

	backup = *index;
	i = 1;
	if (str[i + backup] == q && str[i + backup] != '|')
		i++;
	result = ft_strdup_v2(str, backup, i + backup);
	ft_lstadd_back_v2(&g_arg.list, ft_lstnew_v2(result, q));
	*index = i + backup;
}

int	list_init(char *str)
{
	char	*result;
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	//printf("--------\nstr: %s#\n", str);
	ft_lstclear_v2(&g_arg.list);
	while (i < len)
	{
		while (str[i] == ' ' || str[i] == 9)
			i++;
		if (str[i] == '>' || str[i] == '<' || str[i] == '|')
			special_handler(str, &i, str[i]);
		else if (str[i] && str[i] != ' ')
			handle_others(str, &i, 'o');
	}
	t_arg_list *ptr = g_arg.list;
	while (ptr)
	{
		printf("command: #%s#\nflag: %c\n\n", ptr->content, ptr->flag);
		ptr = ptr->next;
	}
	return (0);
}