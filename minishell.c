#include "minishell.h"

void	command_checker(char *line)
{
	g_data.command = ft_split(line, ' ');

}

void	line_reader(char **env)
{
	char	*line;

	while (1)
	{
		//signal(SIGQUIT, SIG_IGN);
		line = readline("minishell> ");
		eof_control(line);
		if (*line != '\n' && *line != '\0')
			add_history(line);
		//printf("%s\n", line);
		//check_it(line);
		g_data.quit_flag = 0;
		free(line);
	}
}

int	main(int ac, char **av, char **env)
{
	signal(SIGINT, &sigint_voider);
	signal(SIGQUIT, &sigquit_voider);
	g_data.env = env;
	g_data.path = ft_split(getenv("PATH"), ':');
	line_reader(env);
}
