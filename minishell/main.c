/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:20:29 by melih             #+#    #+#             */
/*   Updated: 2023/04/11 03:43:14 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_input()
{
	int	i;

	i = -1;
	while (g_arg.args[++i])
	{
		printf("%s\n", g_arg.args[i]);
	}
}

int	get_first_arg(void)
{
	if (!ft_strncmp("exit", g_arg.args[0], 4))
	{
		printf("exit\n");
		exit(0);
	}
	return (0);
}

void	free_split()
{
	int	i;

	i = -1;
	while (g_arg.args[++i])
		free(g_arg.args[i]);
	free(g_arg.args);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	signal(SIGQUIT, SIG_IGN);
	g_arg.list = NULL;
	g_arg.paths = find_path(envp);
	g_arg.cmd_paths = ft_split(g_arg.paths, ':');
	while (1)
	{
		signal(SIGINT, &sigint_voider);
		input = readline("minishell$ ");
		eof_control(input);
		if (*input != '\n' && *input != '\0')
		{
			add_history(input);
			//g_arg.args = ft_split_quotes(input);
			g_arg.envp = envp;
			list_init(input);
			//print_input();
			//get_first_arg();
			//cmd_process(envp);
			//free_split();
		}
		// else if (*input == 0)
		// {
		// 	system("leaks minishell");
		// }
		free(input);
		// system("leaks minishell");
	}
	return (0);
}
