/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:44:15 by mboutuil          #+#    #+#             */
/*   Updated: 2023/04/11 03:13:11 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	err_msg(char *str)
{
	perror(str);
	return (errno);
}

void ft_free(char **point)
{
	int	i;

	i = 0;

	while (point[i++])
		free(point[i]);
	free(point);
}
void	execute_dashit(char **env, char *cmd)
{
	char	*path;
	char	**cmd1;
	
	cmd1 = ft_split(cmd, ' ');
	path = path_func(env, cmd1);
	if (!path)
	{
		ft_free(cmd1);
		ft_putendl_fd("Pipex : Command not found", 2);
		exit(127);
	}
	if (execve(path, cmd1, env) < 0)
		exit (err_msg("execve :"));
}

char	*path_func(char **env, char **cmd)
{
	char	**path;
	char	*path_tmp;
	char	*pcmd;
	int		i;

	path = NULL;
	path_tmp = NULL;
	if (ft_strchr(*cmd, '/') && !access(*cmd, X_OK))
		return (*cmd);
	while (env++ && *env)
		if (ft_memcmp(*env, "PATH=", 5) == 0)
			path = ft_split(*env + 5, ':');
	if (!path)
		exit (err_msg("path"));
	i = 0;
	while (path[i++])
	{
		pcmd = ft_strjoin(path[i], "/");
		path_tmp = ft_strjoin(pcmd, cmd[0]);
		free(pcmd);
		if (access(path_tmp, X_OK) == 0)
			return (path_tmp);
		else
			free(path_tmp);
	}
	return (NULL);
}
