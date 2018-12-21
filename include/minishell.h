#ifndef MINISHELL
# define MINISHELL

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/includes/libft.h"
# define RED 	"\033[0;31m"
# define YELLOW "\033[1;33m"
# define RESET 	"\033[0m"
# define CYAN	"\033[1;36m"
# define CWD_BUF 4096
# define PROMPT "\n└─Ø "RED"[ minishell ] ¬> "RESET

/*
** echo.c
*/
void	echo(char **command);

/*
** env.c
*/
void	init_env(char **envp);
void	print_env(void);
char	*find_path(char *key, size_t key_len);
int		find_key(char *key);

/*
** env_setting.c
*/
void	set_env(char **args);
void	unset_env(char **args);

/*
** cd.c
*/
void 	change_dir(char *path);
void	cd(char **args);

/*
** utils.c
*/
void	free_strarray(char **table);
void	display_cwd(void);
void	exit_minishell(void);
void	handle_sigint(int sig);

/*
** system_call.c
*/
void	system_call(char **args);

char	**g_envp;

# endif
