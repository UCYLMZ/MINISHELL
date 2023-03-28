/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uyilmaz <uyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:20:46 by melih             #+#    #+#             */
/*   Updated: 2023/03/28 05:30:21 by uyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include "./libft/libft.h"

typedef struct s_arg_list
{
	char				*content;
	struct s_arg_list	*next;
	char				flag;
}	t_arg_list;

struct s_arg
{
	pid_t		pid;
	char		quote_flag;
	char		*cmd;
	char		*pwd;
	char		*paths;
	char		**cmd_paths;
	char		**cmd_args;
	char		**args_temp;
	char		**args;
	char		**envp;
	int			quit_flag;
	t_arg_list	*list;
}	g_arg;

char		*find_path(char **envp);
char		*get_cmd(char **paths, char *cmd);
int			cmd_process(char **envp);
void		sigquit_voider(int signal);
void		eof_control(char *line);
void		sigint_voider(int signal);
char		*find_pwd(char **envp);
char		**ft_split_quotes(char *str);
void		ft_lstdelone_v2(t_arg_list **lst);
void		ft_lstclear_v2(t_arg_list **lst);
t_arg_list	*ft_lstnew_v2(char *content, char flag);
void		ft_lstadd_back_v2(t_arg_list **lst, t_arg_list *new);
int			list_init(void);
char		*ft_strjoin_v2(char *s1, char *s2);

#endif