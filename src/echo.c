#include "../include/minishell.h"

void 	echo_str(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '~')
		ft_printf("%s", find_path("HOME", ft_strlen("HOME")));
	else if (str[0] == '$')
		ft_printf("%s", find_path(str + 1, len - 1));
	else if (str[0] == '\"' && str[len -1] == '\"')
		ft_putnstr(str, len - 2);
	else
		ft_printf("%s", str);
}

void 	echo_iter(char **command)
{
	int	i;

	i = -1;
	while (command[++i])
	{
		if (*command != '\0')
			echo_str(command[i]);
		command[i + 1] ? ft_putchar(' ') : 0;
	}
}

void	echo(char **command)
{
	bool	nl;
	int		start;

	if (!command || !*command)
	{
		ft_printf("\n");
		return ;
	}
	nl = !ft_strcmp(command[0], "-n") ? true : false;
	start = nl == true ? 1 : 0;
	echo_iter(command + start);
	nl == false ? ft_putchar('\n') : 0;
}
