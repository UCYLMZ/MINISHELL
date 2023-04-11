/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:43:50 by uyilmaz           #+#    #+#             */
/*   Updated: 2023/04/11 03:44:14 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_voider(int signal)
{
	// (void)signal;
	// rl_replace_line("", 0);
	// write(1, "\033[2D", 4);
	// ioctl(0, TIOCSTI, "\n");
	// rl_on_new_line();

	(void)signal;
	//rl_replace_line("", 0);
	printf("\033[2D\033[1A");
	printf("minishell$     ");
	ioctl(0, TIOCSTI, "\n");
	//rl_on_new_line();
}

void	eof_control(char *line)
{
	if (!line)
	{
		printf("\033[2D\033[1A");
		printf("minishell$ exit\n");
		exit (0);
	}
}

void	sigquit_voider(int signal)
{
	(void)signal;
	printf("\rminishell$   ");
	printf("\b\b");
}
