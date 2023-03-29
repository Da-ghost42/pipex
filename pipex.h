#ifndef PIPEX_H
#define PIPEX_H
#include<unistd.h>
#include<stdio.h>
#include<sys/errno.h>
#include<sys/wait.h>
#include<fcntl.h>
#include "lib/libft.h"

void	execute_dashit(char **env,char *cmd);
char    *path_func(char **env,char **cmd);
void    child_proc(char **av, char **env, int *fd);
void    parent_proc(char **av,char **env, int *fd);
void	execute_dashit_prime(char **env,char *cmd);
int err_msg(char *str);
#endif