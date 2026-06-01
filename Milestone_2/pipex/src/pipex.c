/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfeofan <alfeofan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 12:00:00 by alfeofan          #+#    #+#             */
/*   Updated: 2026/06/01 23:06:25 by alfeofan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	redirect_io(int input_fd, int output_fd, int *pipe_fd)
{
	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(input_fd);
	close(output_fd);
}

void	child_one(char **argv, char **envp, int *pipe_fd)
{
	int		infile;
	char	**cmd_args;
	char	*cmd_path;

	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror(argv[1]);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}
	check_empty_cmd(argv[2], pipe_fd);
	redirect_io(infile, pipe_fd[1], pipe_fd);
	cmd_args = get_cmd_args(argv[2]);
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_array(cmd_args);
		write(2, "pipex: command not found\n", 25);
		exit(127);
	}
	execve(cmd_path, cmd_args, envp);
}

void	child_two(char **argv, char **envp, int *pipe_fd)
{
	int		outfile;
	char	**cmd_args;
	char	*cmd_path;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror(argv[4]);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}
	check_empty_cmd(argv[3], pipe_fd);
	redirect_io(pipe_fd[0], outfile, pipe_fd);
	cmd_args = get_cmd_args(argv[3]);
	cmd_path = get_cmd_path(cmd_args[0], envp);
	if (!cmd_path)
	{
		free_array(cmd_args);
		write(2, "pipex: command not found\n", 25);
		exit(127);
	}
	execve(cmd_path, cmd_args, envp);
}

static int	fork_and_execute(char **argv, char **envp, int *pipe_fd)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork error"), 1);
	if (pid1 == 0)
		child_one(argv, envp, pipe_fd);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork error"), 1);
	if (pid2 == 0)
		child_two(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		exit_code;

	if (argc != 5)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		write(2, "Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 44);
		return (1);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("Pipe error");
		return (1);
	}
	exit_code = fork_and_execute(argv, envp, pipe_fd);
	return (exit_code);
}
