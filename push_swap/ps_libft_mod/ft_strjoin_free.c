/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:02:50 by thtay             #+#    #+#             */
/*   Updated: 2026/02/24 17:12:53 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc
//
// malloc (s1 cat s2)
//
// ERROR NULL

#include "../push_swap.h"

static size_t	len(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	total;
	size_t	incr;
	char	*ret;

	ret = malloc(len(s1) + len(s2) + 1);
	if (!ret)
		return (NULL);
	total = 0;
	incr = 0;
	while (s1[total])
	{
		ret[total] = s1[total];
		total++;
	}
	while (s2[incr])
	{
		ret[total + incr] = s2[incr];
		incr++;
	}
	ret[total + incr] = '\0';
	if (ft_strlen(s1) && s1 != NULL)
		free(s1);
	return (ret);
}
