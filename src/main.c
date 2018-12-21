#include "../include/minishell.h"

static void	exec_command(char **command)
{
	if (!command || !*command || !**command)
		return ;
	else if (!ft_strcmp(command[0], "echo"))
		echo(command + 1);
	else if (!ft_strcmp(command[0], "cd"))
		cd(command + 1);
	else if (!ft_strcmp(command[0], "setenv"))
		set_env(command + 1);
	else if (!ft_strcmp(command[0], "unsetenv"))
		unset_env(command + 1);
	else if (!ft_strcmp(command[0], "env"))
		print_env();
	else if (!ft_strcmp(command[0], "exit"))
		exit_minishell();
	else
		system_call(command);
}

static void	exec_commands(char **commands)
{
	int	i;
	char **command;

	i = -1;
	while (commands[++i])
	{
		command = ft_strsplit(commands[i], ' ');
		exec_command(command);
		free_strarray(command);
	}
}

int			main(int argc, char **argv, char **envp)
{
	char *line;
	char **commands;

	(void)argc;
	(void)argv;
	init_env(envp);
	while (1)
	{
		signal(SIGINT, handle_sigint);
		display_cwd();
		line = readline(PROMPT);
		if (!line)
			exit_minishell();
		add_history(line);
		commands = ft_strsplit(line, ';');
		free(line);
		exec_commands(commands);
		free_strarray(commands);
	}
	return (0);
}
