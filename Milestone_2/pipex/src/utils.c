/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 12:00:00 by alfeofan          #+#    #+#             */
/*   Updated: 2026/06/01 21:50:25 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*check_path_access(char **paths, char *cmd)
{
	char	*part_path;
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*find_path_env(char *envp[])
{
	int		i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*res_path;

	if (!cmd || cmd[0] == '\0')
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = ft_split(find_path_env(envp), ':');
	if (!paths)
		return (NULL);
	res_path = check_path_access(paths, cmd);
	free_array(paths);
	return (res_path);
}

char	**get_cmd_args(char *cmd)
{
	char	**cmd_args;

	if (!cmd)
		return (NULL);
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		return (NULL);
	return (cmd_args);
}
