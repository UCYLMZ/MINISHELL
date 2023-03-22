#include "minishell.h"

void	eof_control(char *line)
{
	if (!line)
	{
		write(1, "\033[2D", 4);
		printf("exit\n");
		exit (0);
	}
}

void	parser(char *line)
{
	g_data.command = ft_split(line, ' ');
}

void	line_reader(char **env)
{
	char	*line;

	while (1)
	{
		line = readline("minishell> ");
		add_history(line);
		eof_control(line);
		//printf("%s\n", line);
		//check_it(line);
		//g_data.quit_flag = 0;
	}
}

int	main(int ac, char **av, char **env)
{
	signal(SIGINT, &sigint_voider);
	signal(SIGQUIT, SIG_IGN);
	//signal(SIGQUIT, &sigquit_voider);
	g_data.env = env;
	g_data.path = ft_split(getenv("PATH"), ':');
	line_reader(env);
}
