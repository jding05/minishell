#include "../include/minishell.h"

static void	update_oldpwd(char *cwd)
{
	char **oldpwd_args;

	oldpwd_args = (char **)ft_memalloc(sizeof(char *) * 3);
	oldpwd_args[0] = ft_strdup("OLDPWD");
	oldpwd_args[1] = ft_strdup(cwd);
	oldpwd_args[2] = NULL;
	set_env(oldpwd_args);
	free_strarray(oldpwd_args);
}

/*
** go to the target path and update_oldpwd in envp
** if failed, show error message
*/
void 		change_dir(char *path)
{
	char *cwd;
	char buf[CWD_BUF + 1];

	cwd = getcwd(buf, CWD_BUF);
	if (!chdir(path))
		update_oldpwd(cwd);
	else
	{
		ft_printf("cd: ");
		if (access(path, F_OK) == -1)
			ft_printf("no such file or directory: ");
		else if (access(path, W_OK) == -1 || access(path, X_OK) == -1)
			ft_printf("permission denied: ");
		else
			ft_printf("not a directory: ");
		ft_printf("%s\n", path);
	}
}

/*
** 4 conditions: 1. HOME ('~', '--')
**				 2. last dir ('-')
**				 3. more than one arguments
**				 4. one arguement
**					if $ -> check the env path
**					else -> change the path dir
*/
void		cd(char **args)
{
	char	*oldpath;
	char	*env_path;

	if (!args[0] || (!args[1] &&
			(!ft_strcmp(args[0], "~") || !ft_strcmp(args[0], "--"))))
		change_dir(find_path("HOME", ft_strlen("HOME")));
	else if (!ft_strcmp(args[0], "-") && !args[1])
	{
		oldpath = find_path("OLDPWD", ft_strlen("OLDPWD"));
		printf("%s\n", oldpath);
		change_dir(oldpath);
	}
	else if (args[1])
		ft_printf("cd: string not in pwd: %s", args[0]);
	else
	{
		if (args[0][0] == '$')
		{
			if (!(env_path = find_path(args[0] + 1, ft_strlen(args[0]) - 1)))
				change_dir(find_path("HOME", ft_strlen("HOME")));
			else
				change_dir(env_path);
		}
		change_dir(args[0]);
	}
}
