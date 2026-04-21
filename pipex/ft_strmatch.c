/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:20:09 by thtay             #+#    #+#             */
/*   Updated: 2026/04/16 16:20:10 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//returns 1 on match to a given vec, else 0.
int	ft_strmatch(char *vec, char *match)
{
	size_t	mlen;

	mlen = ft_strlen(match);
	if (ft_strnstr(vec, match, mlen) != NULL)
		if (mlen == ft_strlen(vec))
			return (1);
	return (0);
}
