#ifndef PIPE_H
# define PIPE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**envp;
}	t_pipex;

void	error_exit(char *msg);
void	execute(char *cmd, char **envp);
char	*get_path(char *cmd, char **envp);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif