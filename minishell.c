#include "minishell.h"

void	check_it(char *line)
{
	if (!line)
	{
		write(2, "\nexit\n", 5);
		exit(0);
	}
}

void	parser(char *line)
{
	g_data.command = ft_split(line, ' ');
}

void	ctrl_d(int signal)
{
	(void)signal;
	//return ;
	// write(2, "exit\n", 5);
	// exit(0);
	printf("\n");
	line_reader(g_data.env);
}

void	line_reader(char **env)
{
	char	*line;

	while (1)
	{
		signal(SIGINT, ctrl_d);
		line = readline("minishell> ");
		add_history(line);
		check_it(line);
	}
}

int	main(int ac, char **av, char **env)
{
	// if (signal(SIGINT, ctrl_d) == SIG_ERR)
	// 	printf("SIGERR came");
	//signal(SIGQUIT, SIG_IGN);
	g_data.env = env;
	g_data.path = ft_split(getenv("PATH"), ':');
	line_reader(env);
}
