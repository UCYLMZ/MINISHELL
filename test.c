#include "minishell.h"

int main(void)
{
	char *line;
	char **path;
	
	path = ft_split(getenv("PATH"), ':');
	while (1)
	{
		line = readline("minishell: ");
		add_history(line);
		printf("%s\n", line);
	}
}