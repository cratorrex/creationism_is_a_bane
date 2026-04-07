/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:38:00 by thtay             #+#    #+#             */
/*   Updated: 2026/03/26 16:38:01 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	fr_atoi_chr(char ptr)
{
	if (!(ptr >= '0' && ptr <= '9') && !(ptr == '\0' || ptr == '\\')
		&& !(ptr == 'i' || ptr == 'p' || ptr == 'r' || ptr == 'D'))
		return (1);
	return (0);
}

int	ft_atoi_e(char *ptr, int *i)
{
	int		sign;

	*i = 0;
	sign = 1;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == 32)
		ptr++;
	if (*ptr == '+' || *ptr == '-')
		if (*ptr++ == '-')
			sign = -1;
	if (*ptr >= '0' && *ptr <= '9')
	{
		while (*ptr >= '0' && *ptr <= '9')
		{
			if (*i > INT_MAX / 10)
				return (1);
			*i = *i * 10 + (int)(*ptr - '0');
			ptr++;
		}
		if (fr_atoi_chr(*ptr))
			return (1);
		*i = *i * sign;
		return (0);
	}
	return (1);
}
