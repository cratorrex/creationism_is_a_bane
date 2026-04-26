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

//perror runs if any errors
void	px_exec(char **vec, int *pipes, int i)
{
	char	**coni;
	char	*spi;
	int		craf;
	
	if (i == 2)
	{
		dup2(pipes[1], 0);
		dup2(pipes[0], 1);
	}
	if (!vec[i + 2])
	{
		craf = open(vec[i], O_WRONLY);
		dup2(pipes[1], craf);
	}
//		close(pipes[0]);
	coni = ft_split(vec[i], ' ');
	spi = ft_strjoin("/usr/bin/", coni[0]);
	if(!access(spi, X_OK))
		execve(spi, coni, NULL);
	// while (*coni)
	// 	printf ("%s", *coni++);
	perror("pipex");

	px_exit(coni, spi);
}
