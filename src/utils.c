#include "../include/minishell.h"

void		free_strarray(char **table)
{
	int	i;

	if (!table)
		return ;
	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
	table = NULL;
}

inline void	display_cwd(void)
{
	char buf[CWD_BUF + 1];

	getcwd(buf, CWD_BUF);
	printf(CYAN"\n(%s) "RESET, buf);
}

void		exit_minishell(void)
{
	write(1, "exit\n", 6);
	free_strarray(g_envp);
	exit(1);
}

/*
** Handler for SIGINT, caused by
** Ctrl-C at keyboard
*/
void		handle_sigint(int sig)
{
    if (sig == SIGINT)
		exit_minishell();
}
