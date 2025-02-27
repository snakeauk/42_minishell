#include "ft_builtins.h"

int builtin_cd(int argc, char **argv, t_list *minienv)
{
	char	*path;
	char	*pwd;
	char	*oldpwd;
	char	cwd[PATH_MAX];

	if (argc == 1)
		return (0);
	else if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "cd: too many arguments\n");
		return (1);
	}
	if (argv[1] && (ft_strcmp(argv[1], "~") != 0))
		path = argv[1];
	else
		path = minienv_value("__HOME", minienv);
	if (chdir(path) != 0)
	{
		perror("cd error");
		return (1);
	}
	pwd = minienv_value("PWD", minienv);
	oldpwd = minienv_value("OLDPWD", minienv);
	if (oldpwd && pwd && *pwd)
		minienv_update("OLDPWD", pwd, minienv);
	if (pwd && *pwd)
		minienv_update("PWD", getcwd(cwd, PATH_MAX), minienv);
	return (0);
}
