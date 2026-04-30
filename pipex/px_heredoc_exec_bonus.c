/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_heredoc_exec_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:59:08 by thtay             #+#    #+#             */
/*   Updated: 2026/04/29 18:59:09 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_hd_open(t_pipex *cntl, char **vec)
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

void	px_hd_mid(t_pipex *cntl, int i, char **vec)
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

void	px_hd_close(t_pipex *cntl, int i, char **vec)
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

