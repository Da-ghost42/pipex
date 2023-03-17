#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>

void execute_cmd(char *av,char **env)
{
	char **cmd;
	char *path;
	int i;

	i = 0;
	if (!*av)
		exit(0);
	cmd = ft_split(av,' ');
	path = path_func(**env,cmd[0]);

	if (execve(path,cmd,env) < 0)
	{
		printf("error executing the cmommand / the command is not valid");
		exit(0);
	}
}

void c_process(char **av,char **env,int *fd)
{
	int infile;

	infile = open(av[1],O_RDONLY,0777);
	if (infile < 0)
		printf("ERROR WHILE OPENING THE INFILE");
	dup2(fd[1],STDIN_FILENO);
	dup2(infile,STDOUT_FILENO);
	close(fd[0]);
	execute_cmd(av[3],env);
}
void p_process(char **av,char **env,int *fd)
{
	int outfile;

	outfile = open(av[4],O_RDWR | O_CREAT | O_TRUNC,0777);
	if (outfile < 0)
		printf("ERROR WHILE OPENING THE OUTFILE");
	dup2(fd[0],STDIN_FILENO);
	dup2(outfile,STDOUT_FILENO);
	close(fd[1]);
	execute_cmd(av[3],env);
}
int main(int ac,char **av,char **env)
{
	int fd[2];
	int p;
	// int p_fd[2];
	int id;

	if (ac == 5)
	{
		p = pipe(fd);
		if(p < 0)
			printf("ERROR WHILE PIPING");
			id = fork();
		if (id == 0)
			c_process(av,env,fd);
		waitpid(id,NULL,0);
		p_process(av,env,fd);
	}
	else 
	printf("bad arguments number retry !");
}