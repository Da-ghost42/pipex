#include"../pipex.h"

// void cmd_treater(int ac,char **av,int count)
// {
// 	int fd[count];
// 	int i;

// }

// void check_args(int ac, char **av)
// {
// 	int count;
// 	int i;

// 	if (ac > 5)
// 	{
// 		if (ft_strncmp(av[1],"her_doc",8))
// 		{
// 			count = (ac - 4) * 2;
// 			her_doc(av[2]);
// 		}
// 		count = (ac - 3) * 2;
// 		int fd[count];
// 		if (pipe(fd[count]) < 0)
// 			exit(err_msg("pipe fd :"));
// 		while (i < ac - 3)
// 		{
// 			if (fork() == 0)
// 				child_proc();
// 		}
// 		cmd_treater(ac,av,count);
// 	}
// }
int check_if_herdoc(char **str)
{
	if (!ft_strcmp(str[1],"her_doc",8))
		return 1;
	return 0;
}

int main (int ac,char **av,char **env)
{
	int	id;
	int fd[2];
	int infile;
	int i;
	int j;

	i = 0;
	if (ac > 5)
		if (!check_if_herdoc(av));
			her_doc(av[2]); 
		infile = open(av[1],O_RDONLY,0644);
		dup2(infile,STDIN_FILENO);
		while (i < ac -3)
		{
			if (pipe(fd) < 0)
				exit(err_msg("Pipe error"));
			id = fork();
			if (id == 0)
			{
				dup2(fd[1],STDOUT_FILENO);
				j = 2;
				while (j++ < ac -1)
					execute_dashit_prime(env,av[j++]);
			}
		wait(NULL);
		parent_proc(env,av[j]);
		}
}