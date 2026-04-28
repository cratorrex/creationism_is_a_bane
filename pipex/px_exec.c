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
		close(0);
		close(1);
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
		px_exec(vec, i + 3);
		close(0);
		close(1);
		close(2);
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
		dup2(cntl->pipette[i][0], 0);
		dup2(cntl->outfile, 1);
		px_clean(cntl);
		px_exec(vec, i + 3);
		close(0);
		close(1);
		close(2);
		exit(1);
	}
	waitpid(prong, 0, 0);
}

//perror runs if any errors
//int v_i = i + 2;
void	px_exec(char **vec, int v_i)
{
	char	**coni;
	char	*spi;

	coni = ft_split(vec[v_i], ' ');
	spi = ft_strjoin("/usr/bin/", coni[0]);
	if (!access(spi, X_OK))
		execve(spi, coni, NULL);
	perror("pipex");
	px_exit(coni, spi);
}
