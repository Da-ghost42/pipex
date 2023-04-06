/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:46:25 by mboutuil          #+#    #+#             */
/*   Updated: 2023/04/06 02:22:11 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

// void lol_func(char *readed,char *limt,int *fd)
// {
// 	while(1)
// 	{
// 		readed = get_next_line(0);
// 		if(ft_strncmp(readed,limt,ft_strlen(limt)) != 0)
// 			ft_putstr_fd(readed,fd[1]);
// 		exit(EXIT_SUCCESS);
// 	}

// }
// char *read_funct()
// {
// 	int len;
// 	char buffer[10000];

// 	len = read(0,buffer,);
// 	while()

// }
int readed_checker(char *readed,char *lim)
{
	if (!ft_strncmp(readed,lim,ft_strlen(lim)))
		return 1;
	return 0;
}
// void her_doc_helper(char *readed,char lim)
// {
// 	while (1)
// 	{
// 		readed = get_next_line(0);
// 		if (readed_checker(readed,lim))
// 			exit(EXIT_SUCCESS);
// 	}

// }
void goto_herdoc(char *limt)
{
	int fd[2];
	int i;
	char *readed;

	if (pipe(fd) < 0)
		exit(err_msg("pipe"));
	while(1)
	{
		ft_putstr_fd("pipex> ", 1);
		readed = get_next_line(0);
		if (!readed)
			break;
		if (ft_strncmp(readed,limt,ft_strlen(limt)) == 0)
			exit (EXIT_SUCCESS);
		ft_putstr_fd(readed, fd[1]);
	}
		// while (ft_strncmp(readed,limt,ft_strlen(limt)))
		// 		readed = get_next_line(0);
			// ft_putstr_fd(readed,fd[1]);
		// exit (EXIT_SUCCESS);
	// }
	// else 
	// {
	// 	close(fd[1]);
	// 	dup2(fd[0],0);
	// 	wait (NULL);
	// }


}

void child_bonus(char *cmd,char **env)
{
	int fd[2];
	pid_t id;

	if (pipe(fd) < 0)
		exit(err_msg("error :"));
	id = fork();
	if (id < 0)
		exit(err_msg("fork :"));
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execute_dashit(env,cmd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		wait(NULL);
	}

}

int main (int ac ,char **av,char **env)
{
	int fd[2];
	int i;
	int inf;
	int	outf;

	if (ac >= 5)
	{
		if (!ft_strncmp(av[1], "her_doc", 8))
		{
			i = 2;
			outf = open(av[ac - 1],O_RDONLY|O_CREAT|O_APPEND,0644);
			goto_herdoc(av[2]);
		}
		else
		{
			i = 1;
			outf = open(av[ac - 1],O_WRONLY|O_CREAT|O_TRUNC,0644);
			inf = open(av[1],O_RDONLY,0644);
			dup2(inf,STDIN_FILENO);
			dup2(outf,STDOUT_FILENO);
		}	
		while (++i < ac - 2)
			child_bonus(av[i],env);
		execute_dashit(env,av[ac - 2]);
	}
	else 
		ft_putstr_fd("bad arguments number",2);	
		return 0;
}