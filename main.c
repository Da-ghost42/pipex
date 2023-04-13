/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:43:00 by mboutuil          #+#    #+#             */
/*   Updated: 2023/04/12 01:56:04 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

/*the mandatory talk about emplementing pipes 
and rederecting data between processes"./pipex infile "ls -l" "wc -l" outfile".
PIPE is a system call take integer pointer {---pipe(int fd[2])---}
fd[0] is the read-end of the pipe
fd[1] is the write-end of the pipe
as we see we can use pipes to hold data 
FORK is function takes nothing as parameter {---fork()---}
we use fork to create another process 
the new process created named the child 
process it is an exact copy of main process (parent process)
but with different file descriptors and process id and a block of memory 
and that was exactly what we need in this project  */
int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	id;

	if (ac == 5)
	{
		if (!*env)
			exit(err_msg("NO PATH! :"));
		if (pipe(fd) < 0)
			exit (err_msg("Pipe"));
		id = fork();
		if (id == 0)
			child_proc(av, env, fd);
		else
			wait(NULL);
		parent_proc(av, env, fd);
	}
	else 
	ft_putstr_fd("PIPEX : bad arguments number",2);
	exit (1);
return (0);
}
