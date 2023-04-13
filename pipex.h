/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutuil <mboutuil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:43:36 by mboutuil          #+#    #+#             */
/*   Updated: 2023/04/08 23:35:49 by mboutuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<stdio.h>
# include<sys/errno.h>
# include<sys/wait.h>
# include<fcntl.h>
# include "lib/libft.h"
# include"get/get_next_line.h"

void	execute_dashit(char **env, char *cmd);
char	*path_func(char **env, char **cmd);
void	child_proc(char **av, char **env, int *fd);
void	parent_proc(char **av, char **env, int *fd);
int		err_msg(char *str);
// void goto_herdoc(char *limt);

#endif
