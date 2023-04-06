/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:43:47 by mboutuil          #+#    #+#             */
/*   Updated: 2023/04/02 14:44:31 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void child_proc(char **av, char **env, int *fd)
{
	int infile;

	infile = open(av[1],O_RDONLY);
	if (infile < 0)
		exit(err_msg("cannot open the infile :"));
	dup2(infile,STDIN_FILENO);
	dup2(fd[1],STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	close(fd[1]);
	execute_dashit(env,av[2]);
}
void	parent_proc(char **av,char **env,int *fd)
{
	int outfile;

	outfile = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile < 0)
		exit (err_msg("cannot open the outfile :"));
	dup2(fd[0],STDIN_FILENO);
	dup2(outfile,STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	execute_dashit(env,av[3]);
}

