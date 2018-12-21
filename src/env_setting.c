#include "../include/minishell.h"

static char		**realloc_env(int total_key)
{
	char	**new_g_env;
	int		i;

	new_g_env = (char **)ft_memalloc(sizeof(char *) * (total_key + 1));
	i = -1;
	while (g_envp[++i] && i < total_key)
	{
		new_g_env[i] = ft_strdup(g_envp[i]);
		free(g_envp[i]);
		g_envp[i] = NULL;
	}
	free(g_envp);
	g_envp = NULL;
	return (new_g_env);
}

static void		set_env_single(char **args)
{
	char *new_value;
	int	key;

	key = find_key(args[0]);
	new_value = ft_strjoin("=", args[1]);
	if (g_envp[key])
	{
		free(g_envp[key]);
		g_envp[key] = args[1] ?
			ft_strjoin(args[0], new_value) : ft_strjoin(args[0], "=");
	}
	else
	{
		g_envp = realloc_env(key + 1);
		g_envp[key] = args[1] ?
			ft_strjoin(args[0], new_value) : ft_strjoin(args[0], "=");
	}
	if (ft_strcmp(args[0], "OLDPWD"))
		ft_printf("[%s] (setenv)\n", g_envp[key]);
	free(new_value);
}

void			set_env(char **args)
{
	int argc;

	argc = 0;
	while (args[argc])
		argc++;
	if (argc != 2)
		ft_printf("Error: Invalid number of arguments (setenv)\n");
	else
		set_env_single(args);
}

static void		unset_env_single(int key)
{
	ft_printf("[%s] (unsetenv)\n", g_envp[key]);
	free(g_envp[key]);
	g_envp[key] = NULL;
	while (g_envp[key + 1])
	{
		g_envp[key] = ft_strdup(g_envp[key + 1]);
		free(g_envp[key + 1]);
		key++;
	}
	g_envp = realloc_env(key);
}

void			unset_env(char **args)
{
	int i;
	int key;

	i = -1;
	if (!args[0])
		ft_printf("Error: Too few arguments (unsetenv)\n");
	else
	{
		while (args[++i])
		{
			key = find_key(args[i]);
			if (g_envp[key])
				unset_env_single(key);
		}
	}
}
