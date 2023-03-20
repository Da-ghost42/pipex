#include"pipex.h"

int err_msg(void)
{
	perror("ATTENTION :");
	return(errno);
}

void child_proc(char **av, char **env, int *fd)
{
	int infile;

	infile = open(av[1],O_RDONLY);
	if (infile < 0)
		write(1,"cannot finf the infile",23);
	dup2(fd[1],STDIN_FILENO);
	dup2(infile,STDOUT_FILENO);
	close(fd[0]);
	execute_dashit(env,av[2]);
}
void	main_proc(char **av,char **env,int *fd)
{
	int outfile;

	outfile = open(av[4],O_WRONLY | O_TRUNC | O_CREAT,0777);
	if (outfile < 0)
		write(1,"error while opening outfile\n",28);
	dup2(fd[0],STDIN_FILENO);
	dup2(outfile,STDOUT_FILENO);
	close(fd[1]);
	execute_dashit(env,av[3]);
}
