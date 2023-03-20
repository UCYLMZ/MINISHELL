#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>

struct	s_data
{
	char	**env;
	char	**path;
	char	**command;
}	g_data;

char	**ft_split(const char *s, char c);
void	signal_voider(int signal);
void	line_reader(char **env);
#endif