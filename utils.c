/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:44:15 by mboutuil          #+#    #+#             */
/*   Updated: 2023/04/05 05:04:43 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	err_msg(char *str)
{
	perror(str);
	return (errno);
}

void	execute_dashit(char **env, char *cmd)
{
	char	*path;
	char	**cmd1;
	int		i;

	i = 0;
	cmd1 = ft_split(cmd, ' ');
	path = path_func(env, cmd1);
	if (!*path)
		exit (err_msg("error finding the path :"));
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
	if (ft_strchr(*cmd, '/') && !access(*cmd,X_OK))
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
			break ;
		free(path_tmp); //exit status if access failed
	}
	return (path_tmp);
}
