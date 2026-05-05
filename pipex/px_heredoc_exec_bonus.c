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

#include "pipex_bonus.h"

void	px_hd_open(t_pipex *cntl, char **vec)
{
	pid_t	prong;
	char	*line;

	cntl->limit = ft_strjoin(cntl->limit, "\n");
	while (1)
	{
		line = get_next_line(0);
		if (ft_strmatch(line, cntl->limit))
			break ;
		ft_putstr_fd(line, cntl->pipette[0][1]);
		free(line);
	}
	free (line);
	free (cntl->limit);
	prong = fork();
	if (prong == 0)
	{
		dup2(cntl->pipette[0][0], 0);
		dup2(cntl->pipette[1][1], 1);
		px_clean(cntl);
		px_exec(vec, 0 + 3);
	}
}

void	px_hd_mid(t_pipex *cntl, int i, char **vec)
{
	pid_t	prong;

	prong = fork();
	if (prong == 0)
	{
		dup2(cntl->pipette[i][0], 0);
		dup2(cntl->pipette[i + 1][1], 1);
		px_clean(cntl);
		px_exec(vec, i + 3);
	}
}

pid_t	px_hd_close(t_pipex *cntl, int i, char **vec)
{
	pid_t	prong;

	prong = fork();
	if (prong == 0)
	{
		dup2(cntl->pipette[i][0], 0);
		dup2(cntl->outfile, 1);
		px_clean(cntl);
		px_exec(vec, i + 3);
	}
	return (prong);
}
