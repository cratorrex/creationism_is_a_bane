/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:23:44 by thtay             #+#    #+#             */
/*   Updated: 2026/04/20 17:23:45 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_clean(t_pipex *cntl)
{
	int	i;

	i = 0;
	close(cntl->infile);
	close(cntl->outfile);
	while (i < cntl->pipe_size)
	{
		if (cntl->pipette[i][1])
			close(cntl->pipette[i][1]);
		if (cntl->pipette[i][0])
			close(cntl->pipette[i][0]);
		i++;
	}
	free(cntl->pipette);
}

void	px_exit(char **split, char *join)
{
	char	**init;

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
