#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <readline/readline.h>

struct	s_data
{
	char	**env;
	char	**path;
	char	**command;
	int		quit_flag;
}	g_data;

char	**ft_split(const char *s, char c);
void	eof_control(char *line);
void	sigint_voider(int signal);
void	sigquit_voider(int signal);
void	line_reader(char **env);
#endif