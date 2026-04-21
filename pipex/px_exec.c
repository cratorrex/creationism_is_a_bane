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
void	px_exec(char **vec)
{
		char **coni;
		char *spi;
		
		coni = ft_split(vec[2], ' ');
		spi = ft_strjoin("/usr/bin/", coni[0]);
		// while (*coni)
		// 	printf ("%s", *coni++);
		execve(spi, coni, NULL);
		perror("pipex");

		px_exit(coni, spi);
}
