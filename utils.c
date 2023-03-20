#include"pipex.h"

void	execute_dashit(char **env,char *cmd)
{
	char	*path;
	char	**cmd1;
	int		i;

	i = 0;
	cmd1 = ft_split(cmd,' ');
	path = path_func(env,cmd1);
	if (!*path)
	{
		ft_printf(STDERR_FILENO,"%s",strerror(err_msg()));
		exit(err_msg());
	}
	if (execve(path,cmd1,env) < 0)
		exit (err_msg());
}

char *path_func(char **env,char **cmd)
{
	char	**path;
	char	*pcmd;
	int		i;

	i = 0;
	while(ft_memcmp(*env,"PATH",4))
		env++;
	path = ft_split(*env + 5 , ':');
	pcmd = ft_strjoin("/",cmd[0]);
	while (path[i++])
	{
		path = ft_strjoin(path[i],cmd);
		if (access(path,X_OK) < 0)
		{
			free(path);
			exit(err_msg());
		}
	}
	return (path);
}