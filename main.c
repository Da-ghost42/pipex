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
int main (int ac,char **av,char **env)
{
	int	fd[2];
	int	id;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
		/*the pipe taking fd as an argument and it return -1 in case of error
		so the pipe here will be a way of communication between child proc 
		and parent proc */
			exit (err_msg("problem while piping"));
		id = fork();
		/*we need to execute two commands so we need two process to 
		do that the main reason why we use fork(),
		it returns the id of the current process{main process} and return 0 
		if the current process running is child process,they're running at the same time 
		and we need to execute the command 1 and redirect the output as input 
		to the second command*/
		if (id == 0)
			child_proc(av,env,fd);
		wait(NULL);
		parent_proc(av,env,fd);
	}
	exit(err_msg("bad arguments number"));
}