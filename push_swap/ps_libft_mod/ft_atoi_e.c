/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:23:19 by thtay             #+#    #+#             */
/*   Updated: 2026/02/24 14:23:22 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// \f \n \r \t \v ' '
// 12 10 13 09 11 32
//
// modified for push_swap to check for initial errors
// sets error switch to +2
// 2147483647 anyways
//

#include "../push_swap.h"

static int	parse_num(char *ptr, int sign, char *error)
{
	int	num;

	num = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		num = num * 10 + (int)(*ptr - '0');
		ptr++;
	}
	if (!(*ptr >= '0' && *ptr <= '9') && !(*ptr == '\0' || *ptr == '\\'))
		*error = *error | 2;
	return (num * sign);
}

int	ft_atoi_e(const char *nptr, char *error)
{
	char	*ptr;
	int		sign;

	ptr = (char *)nptr;
	sign = 1;
	while ((*ptr >= 9 && *ptr <= 13) || *ptr == 32)
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	return (parse_num(ptr, sign, error));
}
