/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:48:46 by thtay             #+#    #+#             */
/*   Updated: 2026/03/02 19:48:47 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	**ps_rotate(int **stack)
{
	int	temp[2];
	int	len;
	int	i;

	i = 0;
	len = ft_arrlen((char **)stack);
	temp[0] = stack[0][0];
	temp[1] = stack[0][1];
	while (stack[i + 1] && i < len)
	{
		stack[i][0] = stack[i + 1][0];
		stack[i][1] = stack[i + 1][1];
		i++;
	}
	stack[i][0] = temp[0];
	stack[i][1] = temp[1];
	return (stack);
}
