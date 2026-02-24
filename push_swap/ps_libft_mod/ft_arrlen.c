/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:31:16 by thtay             #+#    #+#             */
/*   Updated: 2026/02/24 16:54:19 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// include libraries at the start of files since compiler reads top down
// man size_t >~<
// unistd.h >> size_t
//

#include "../push_swap.h"

size_t	ft_arrlen(char **s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len ++;
		s ++;
	}
	return (len);
}
