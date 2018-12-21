#include "../include/minishell.h"

void	new_process_to_exec(char *exec, char **args)
{
	pid_t	parent;
	int		stat_loc;

	parent = fork();
	if (parent > 0)
		wait(&stat_loc);
	else if (parent == 0)
		execve(exec, args, g_envp);
	else if (parent < 0)
		ft_printf("minishell: Failed to create a new process\n");
}

void	check_bin_path(char **args)
{
	char	**paths;
	char	*exec_name;
	char	*bin_path;
	int		i;

	paths = ft_strsplit(find_path("PATH", 4), ':');
	exec_name = ft_strjoin("/", args[0]);
	i = -1;
	while (paths && paths[++i])
	{
		bin_path = ft_strjoin(paths[i], exec_name);
		if (access(bin_path, F_OK) == 0)
		{
			new_process_to_exec(bin_path, args);
			free(exec_name);
			free(bin_path);
			free_strarray(paths);
			return ;
		}
		free(bin_path);
	}
	free_strarray(paths);
	ft_printf("minishell: command not found: %s\n", args[0]);
}

void	system_call(char **args)
{
	struct stat buf;

	if (lstat(args[0], &buf) != -1)
	{
		if (buf.st_mode & S_IFDIR)
			change_dir(args[0]);
		else if (buf.st_mode & S_IXUSR)
			new_process_to_exec(args[0], args);
	}
	else
		check_bin_path(args);
}
