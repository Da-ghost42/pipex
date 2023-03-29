#include"pipex.h"

int err_msg(char *str)
{
	perror(str);
	return(errno);
}

void	execute_dashit(char **env,char *cmd)
{
	char	*path;
	char	**cmd1;
	int		i;

	i = 0;
	cmd1 = ft_split(cmd,' ');
	path = path_func(env,cmd1);
	printf("%s\n", path);
	if (!*path)
		exit(err_msg("error finding the path :"));
	if (execve(path,cmd1,env) < 0)
		exit (err_msg("execve :"));
}

char *path_func(char **env,char **cmd)
{
	char	**path;
	char	*path_tmp = NULL;
	char	*pcmd;
	int		i;

	path = NULL;
	if (ft_strchr(*cmd, '/'))
		if (access(*cmd, X_OK) == 0)
			return (*cmd);
	while(env && *env)
	{
		if (ft_memcmp(*env,"PATH=", 5) == 0)
			path = ft_split(*env + 5, ':');
		env++;
	}
	if (!path)
		exit(err_msg("path"));
	i = 0;
	while (path[i])
	{
		pcmd = ft_strjoin(path[i],"/");
		path_tmp = ft_strjoin(pcmd,cmd[0]);
		free(pcmd);
		if (access(path_tmp,X_OK) == 0)
			break;
		free(path_tmp);
		i++;
	    exit(err_msg("the cmd is not valid :"));
	}
	return (path_tmp);
}
