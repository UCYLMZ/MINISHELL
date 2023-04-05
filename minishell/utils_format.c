#include "minishell.h"

int	pass_quote(char *str, char q)
{
	int i;

	i = 0;
	while (str[i] == q)
		i++;
	return (i);
}

char	first_quote(char *str)
{
	int		i;
	char	q;

	i = -1;
	q = 0;
	while (str[++i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			q = str[i];
			return (q);
		}
	}
	return (0);
}