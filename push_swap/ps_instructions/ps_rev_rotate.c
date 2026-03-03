/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:48:30 by thtay             #+#    #+#             */
/*   Updated: 2026/03/02 19:48:31 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	**ps_rev_rotate(int **stack)
{
	int	temp[2];
	int	len;

	len = ps_stackLen(stack) + 1;
	if (len == 0)
		return (stack);
	if (stack[len - 1][0] == 0)
		len --;
	temp[0] = stack[len - 1][0];
	temp[1] = stack[len - 1][1];
	while (len > 1)
	{
		len--;
		stack[len][0] = stack[len - 1][0];
		stack[len][1] = stack[len - 1][1];
	}
	stack[0][0] = temp[0];
	stack[0][1] = temp[1];
	return (stack);
}
