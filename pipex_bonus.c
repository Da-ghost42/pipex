/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:46:25 by mboutuil          #+#    #+#             */
/*   Updated: 2023/04/13 02:53:03 by mboutuil         ###   ########.fr       */
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

// void her_doc_helper(char *readed,char lim)
// {
// 	while (1)
// 	{
// 		readed = get_next_line(0);
// 		if (readed_checker(readed,lim))
// 			exit(EXIT_SUCCESS);
// 	}

// }
void	goto_herdoc(char *limt)
{
	char	*readed;
	int		tmp;
	tmp = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (tmp < 0)
		exit (err_msg("tmp :"));
	while (1)
	{
		ft_putstr_fd("pipex> ", 1);
		readed = get_next_line(0);
		if (!readed)
			break;
		if (!ft_memcmp(readed, limt, ft_strlen(readed + 1)))
				break ;
			// exit (EXIT_SUCCESS);
		ft_putstr_fd(readed, tmp);
	}
		// close(tmp);
}

void	child_bonus(char *cmd, char **env)
{
	int		fd[2];
	pid_t	id;
	
	if (pipe(fd) < 0)
		exit(err_msg("error :"));
	id = fork();
	if (id < 0)
		exit(err_msg("fork :"));
	// dup2(tmp,0);
	if (id == 0)
	{
		// write (0,"ola",3);
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execute_dashit(env, cmd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		wait (NULL);
	}
}

void	o_file(int i, char **av, int ac)
{
		// wait(NULL);
	int	inf;
	int	outf;
	int tmp;

	if (i == 2)
	{
		outf = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		tmp = open(".tmp",O_RDONLY);
		if (outf < 0 || tmp < 0)
			exit(err_msg("cannot open the outfile"));
		dup2(tmp,STDIN_FILENO);
		close(tmp);
		// write(2,"hello",5);
		dup2(outf,STDOUT_FILENO);
	}
	if (i == 1)
	{
		outf = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		inf = open(av[1], O_RDONLY, 0644);
		if (inf < 0 || outf < 0)
			exit(err_msg("cannot open inf nd outf"));
		dup2(inf, STDIN_FILENO);
		dup2(outf, STDOUT_FILENO);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i = -1;
	// int	outf ;

	if (ac >= 5)
	{
		if (!ft_strncmp(av[1], "here_doc", 8))
		{
			i = 2;
	// outf = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	// 	dup2(outf, 1);
		// close(outf);
			goto_herdoc(av[2]);
			o_file(i, av, ac);
		}
		else
		{
			i = 1;
			o_file(i, av, ac);
		}
		while (++i < ac - 2)
		// wait (NULL);
			child_bonus(av[i], env);
		execute_dashit(env, av[ac - 2]);
	}
	else
		ft_putstr_fd("bad arguments number", 2);
	return (0);
}
