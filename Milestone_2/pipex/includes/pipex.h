/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 12:00:00 by alfeofan          #+#    #+#             */
/*   Updated: 2026/06/01 22:06:48 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "../libft/libft.h"

// utils.c
char	*find_path_env(char **envp);
char	*get_cmd_path(char *cmd, char **envp);
char	**get_cmd_args(char *cmd);

// pipex.c
void	child_one(char **argv, char **envp, int *pipe_fd);
void	child_two(char **argv, char **envp, int *pipe_fd);

// check_and_free.c
void	free_array(char **arr);
void	check_empty_cmd(char *cmd, int *pipe_fd);

#endif
