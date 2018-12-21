#include "../include/minishell.h"

void	init_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	g_envp = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i])
		g_envp[i] = ft_strdup(envp[i]);
}

void	print_env(void)
{
	int	i;

	i = -1;
	while (g_envp[++i])
		ft_putendl(g_envp[i]);
}

char	*find_path(char *key, size_t key_len)
{
	int	i;

	i = -1;
	while (g_envp[++i])
		if (!ft_strncmp(g_envp[i], key, key_len) && g_envp[i][key_len] == '=')
			 return (g_envp[i] + key_len + 1);
	return ("");
}

/*
** return the key index of the g_envp, if there is no match, return NULL position
*/
int		find_key(char *key)
{
	int		i;
	size_t	len;

	len = ft_strlen(key);
	i = -1;
	while (g_envp[++i])
		if (!ft_strncmp(g_envp[i], key, len) && g_envp[i][len] == '=')
			return (i);
	return (i);
}
