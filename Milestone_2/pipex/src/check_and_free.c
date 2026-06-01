/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 12:00:00 by alfeofan          #+#    #+#             */
/*   Updated: 2026/06/01 22:06:46 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_array(char **arr)
{
	int		i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	check_empty_cmd(char *cmd, int *pipe_fd)
{
	if (!cmd || cmd[0] == '\0')
	{
		write(2, "pipex: : command not found\n", 27);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(127);
	}
}
