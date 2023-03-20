#include"pipex.h"

void	execute_dashit(char **env,char **av)
{
	char	*path;
	char	**cmd;
	int		i;

	i = -1;
	cmd = ft_split(av,' ');
	

}

char	*path_func(char **env,char **cmd)
{
	char	**str;
	char	*cmd1;
	char	*path;
	int		i;

	i = 0;
	while(ft_memcmp(*env,"PATH",4))
		env++;
	str = ft_split(*env+ 5,':');
	cmd = ft_strjoin("/",cmd1[0]);
	while (str[i++])
	{
		path = ft_strjoin(str[i],cmd);
		if (access(path,X_OK) < 0)
		{
			free(path);
			exit(err_msg());
		}
	}
return (path);
}