#include"pipex.h"

int main (int ac,char **av,char **env)
{
	int	fd[2];
	int	p;
	int e;
	int	id;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			write(1,"error while piping that shit\n",25);
		id = fork();
		if (id == 0)
			child_proc(av,env,fd);
		wait(NULL);
		main_proc(av,env,fd);
	}
	myfprintf(1,"%s",strerror(err_msg()));
}