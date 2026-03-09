/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:56:09 by thtay             #+#    #+#             */
/*   Updated: 2026/03/09 16:56:10 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ret_push(int ***stack_a, int ***stack_b)
{
	while (stack_b[0][0][1])
	{
		ps_push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	ps_sort_radix(int ***stack_a, int ***stack_b, int len)
{
	int	i;
	int	r;

	r = 1;
	while (!(order_pass(*stack_a, 0) & 128))
	{
		i = 0;
		while (i < len)
		{
			if (stack_a[0][0][1] & r)
			{
				*stack_a = ps_rotate(*stack_a);
				ft_printf("ra\n");
			}
			else
			{
				ps_push(stack_a, stack_b);
				ft_printf("pb\n");
			}
			i++;
		}
		ret_push(stack_a, stack_b);
		r << 1;
	}
}
