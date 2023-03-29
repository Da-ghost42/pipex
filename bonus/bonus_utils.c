#include"../pipex.h"

void	execute_dashit_prime(char **env,char *cmd)
{
	char	*path;
	char	**cmd1;
	int		i;

	i = 0;
	cmd1 = ft_split(cmd,' ');
	path = path_func(env,cmd1);
	if (!*path)
		exit(err_msg("error finding the path :"));
	if (execve(path,cmd1,env) < 0)
		exit (err_msg("execve :"));
}