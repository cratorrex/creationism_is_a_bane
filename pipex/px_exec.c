/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:00:59 by thtay             #+#    #+#             */
/*   Updated: 2026/04/20 17:01:00 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_openi(t_pipex *cntl, char **vec)
{
	pid_t	prong;

	prong = fork();
	if (prong)
	{
		dup2(cntl->infile, 0);
		dup2(cntl->pipette[0][1], 1);
		px_clean(cntl);
		px_exec(vec, 0 + 2);
		px_close_fd();
		exit(1);
	}
	waitpid(prong, 0, 0);
}

void	px_mid(t_pipex *cntl, int i, char **vec)
{
	pid_t	prong;

	prong = fork();
	if (prong)
	{
		dup2(cntl->pipette[i][0], 0);
		dup2(cntl->pipette[i + 1][1], 1);
		px_clean(cntl);
		px_exec(vec, i + 2);
		px_close_fd();
		exit(1);
	}
	waitpid(prong, 0, 0);
}

void	px_closef(t_pipex *cntl, int i, char **vec)
{
	pid_t	prong;

	prong = fork();
	if (prong)
	{
		dup2(cntl->pipette[i - 1][0], 0);
		dup2(cntl->outfile, 1);
		px_clean(cntl);
		px_exec(vec, i + 2);
		px_close_fd();
		exit(1);
	}
	waitpid(prong, 0, 0);
}

static void	px_set_fixpath(char *pathos[8])
{
	pathos[0] = "/usr/local/sbin/";
	pathos[1] = "/usr/local/bin/";
	pathos[2] = "/usr/sbin/";
	pathos[3] = "/usr/bin/";
	pathos[4] = "/sbin/";
	pathos[5] = "/bin/";
	pathos[6] = "/usr/games/";
	pathos[7] = "/usr/local/games/";
}

//perror runs if any errors
//int v_i = i + 2;
void	px_exec(char **vec, int v_i)
{
	char	**coni;
	char	*spi;
	char	*pathos[8];
	int		i;

	px_set_fixpath(pathos);
	i = 0;
	while (i < 8)
	{
		coni = ft_split(vec[v_i], ' ');
		spi = ft_strjoin(pathos[i], coni[0]);
		if (!access(spi, X_OK) && spi != NULL)
			execve(spi, coni, NULL);
		px_exit(coni, spi);
		i++;
	}
	perror("pipex: command not found");
}

///// catch cases
/// cd
//bash : err:(null) / out:(null)
//zsh  : err:does a pwd / out:(null)
