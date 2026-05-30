#include "pipe.h"

static char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full;
	char	*tmp;
	int		i;

	paths = ft_split(find_path(envp), ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = get_path(args[0], envp);
	if (!path)
		error_exit("command");
	execve(path, args, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	error_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}