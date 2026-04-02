/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:38:00 by thtay             #+#    #+#             */
/*   Updated: 2026/03/26 16:38:01 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_atoi_e(char *ptr, double *i)
{
	int		sign;

	*i = 0;
	sign = 1;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == 32)
		ptr++;
	if (*ptr == '+' || *ptr == '-')
		if (*ptr++ == '-')
			sign = -1;
	if (sign == -1 && *ptr == 0)
		return (1);
	while (*ptr >= '0' && *ptr <= '9')
	{
		if (*i > INT_MAX / 10)
			return (1);
		*i = *i * 10 + (int)(*ptr - '0');
		ptr++;
	}
	if (!(*ptr >= '0' && *ptr <= '9') && !(*ptr == '\0'
			|| *ptr == '\\' || *ptr == '.'))
		return (1);
	*i = *i * sign;
	return (0);
}

//Assigns the double, given a string (accepts one "-" before number).
//return 0 if no error, return 1 if error.
//why did norm yell at me for line 60 "*x * y"...
int	ft_atod_e(char *str, double *f)
{
	char	*fstr;
	double	dp;

	dp = 0.1;
	if (!str)
		return (1);
	if (ft_atoi_e(str, f))
		return (1);
	fstr = ft_strchr(str, '.') + 1;
	if (fstr == (char *)1)
		return (0);
	if (ft_strchr(str, '-'))
		dp *= -1;
	while (*fstr >= '0' && *fstr <= '9')
	{
		*f += (int)(*fstr - '0')*dp;
		dp /= 10;
		fstr ++;
	}
	if (!(*fstr >= '0' && *fstr <= '9') && !(
			*fstr == '\0' || *fstr == '\\'))
		return (1);
	return (0);
}
