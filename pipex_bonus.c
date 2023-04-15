/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:46:25 by mboutuil          #+#    #+#             */
/*   Updated: 2023/04/15 15:00:31 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	goto_herdoc(char *limt)
{
	char	*readed;
	char	*lim;
	int		tmp;

	lim = ft_strjoin(limt, "\n");
	tmp = open("/tmp/.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (tmp < 0)
		exit (err_msg("tmp :"));
	while (1)
	{
		ft_putstr_fd("pipex> ", 1);
		readed = get_next_line(0);
		if (!readed)
			break ;
		if (!ft_memcmp(readed, lim, ft_strlen(readed)))
		{
			free(lim);
			break ;
		}
		ft_putstr_fd(readed, tmp);
	}
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
	if (id == 0)
	{
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
	int	inf;
	int	outf;
	int	tmp;
	int	j;

	j = 0;
	if (i == 2)
	{
		outf = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		tmp = open("/tmp/.tmp", O_RDONLY);
		if (outf < 0 || tmp < 0)
			exit(err_msg("cannot open the outfile"));
		dup2(tmp, STDIN_FILENO);
		close(tmp);
		dup2(outf, STDOUT_FILENO);
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
	int	i;

	i = -1;
	if (ac >= 5)
	{
		if (!ft_strncmp(av[1], "here_doc", 8))
		{
			i = 2;
			goto_herdoc(av[2]);
			o_file(i, av, ac);
		}
		else
		{
			i = 1;
			o_file(i, av, ac);
		}
		while (++i < ac - 2)
			child_bonus(av[i], env);
		execute_dashit(env, av[ac - 2]);
	}
	else
		ft_putstr_fd("bad arguments number", 2);
	return (0);
}
