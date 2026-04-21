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
