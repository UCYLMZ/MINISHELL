#include "minishell.h"

void	sigint_voider(int signal)
{
	(void)signal;
	write(1, "\033[A", 3);
	ioctl(0, TIOCSTI, "\n");
}

void	sigquit_voider(int signal)
{
	(void)signal;

	// ioctl(0, TIOCSTI, " ");
	// write(1, "\033[D", 3);
	// ioctl(0, TIOCSTI, NULL);
	// if (g_data.quit_flag == 1)
	// {
	// 	printf("in");
	// 	write(1, "\033[2D", 4);
	// 	write(1, "  ", 2);
	// 	write(1, "\033[2D", 4);
	// 	g_data.quit_flag = 0;
	// }
	// printf("sigquit\n");
	// g_data.quit_flag = 1;
}
