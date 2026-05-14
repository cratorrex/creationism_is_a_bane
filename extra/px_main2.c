#include "pipex.h"

//compile main.c -lft -Llibft

void	px_exit(char **split, char *join);

int main(int c, char **v)
{
	int infile = open(v[1], O_RDONLY);
	// execve cmd1
	int pipe1[2]; pipe(pipe1);
	// execve cmd2
	int pipe2[2]; pipe(pipe2);
	// execve cmd3
	int outfile = open(v[5], O_WRONLY | O_CREAT | O_TRUNC);
	c = 0;

	int fork1 = fork();
	if (fork1)
	{
		dup2(infile, 0);
		dup2(pipe1[1], 1);
		close(pipe1[1]);
		close(infile);

		char	**coni;
		char	*spi;

		coni = ft_split(v[2], ' ');
		spi = ft_strjoin("/usr/bin/", coni[0]);

		execve(spi, coni, NULL);
		perror("px_test1\n");
		px_exit(coni, spi);
		exit(0);
	}
	waitpid(fork1, 0, 0);

	fork1 = fork();
	if (fork1)
	{
		close(pipe1[1]);
		dup2(pipe1[0], 0);
		dup2(pipe2[1], 1);

		char	**coni;
		char	*spi;

		coni = ft_split(v[3], ' ');
		spi = ft_strjoin("/usr/bin/", coni[0]);

		execve(spi, coni, NULL);
		perror("px_test2\n");
		px_exit(coni, spi);
		exit(0);
	}
	waitpid(fork1, 0, 0);

	fork1 = fork();
	if (fork1)
	{
		close(pipe2[1]);
		dup2(pipe2[0], 0);
		dup2(outfile, 1);
		close(outfile);

		char	**coni;
		char	*spi;

		coni = ft_split(v[4], ' ');
		spi = ft_strjoin("/usr/bin/", coni[0]);

		execve(spi, coni, NULL);
		perror("px_test3\n");
		px_exit(coni, spi);
		exit(0);
	}
	waitpid(fork1, 0, 0);

	close(pipe1[1]);
	close(pipe1[0]);
	close(pipe2[1]);
	close(pipe2[0]);
	close(infile);
	close(outfile);
	close(0); close(1); close(2);
}





void	px_exit(char **split, char *join)
{
	char **init;

	if (*split)
	{
		init = split;
		while (*split)
		{
			free (*split);
			split ++;
		}
		free (init);
	}
	free (join);
}
