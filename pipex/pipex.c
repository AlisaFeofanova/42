#include "pipe.h"

static void	child_one(t_pipex *px, char **argv)
{
	dup2(px->infile, STDIN_FILENO);
	dup2(px->fd[1], STDOUT_FILENO);
	close(px->fd[0]);
	execute(argv[2], px->envp);
}

static void	child_two(t_pipex *px, char **argv)
{
	dup2(px->fd[0], STDIN_FILENO);
	dup2(px->outfile, STDOUT_FILENO);
	close(px->fd[1]);
	execute(argv[3], px->envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;

	if (argc != 5)
		error_exit("Usage: ./pipex infile cmd1 cmd2 outfile");

	px.envp = envp;
	px.infile = open(argv[1], O_RDONLY);
	px.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);

	if (px.infile < 0 || px.outfile < 0)
		error_exit("file");

	if (pipe(px.fd) == -1)
		error_exit("pipe");

	px.pid1 = fork();
	if (px.pid1 == 0)
		child_one(&px, argv);

	px.pid2 = fork();
	if (px.pid2 == 0)
		child_two(&px, argv);

	close(px.fd[0]);
	close(px.fd[1]);

	waitpid(px.pid1, NULL, 0);
	waitpid(px.pid2, NULL, 0);
	return (0);
}