/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_nb3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:12:29 by thtay             #+#    #+#             */
/*   Updated: 2026/03/05 16:12:31 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	nb_sort_3(int ***stack_a)
{
	if (stack_a[0][0][1] == 3)
	{
		*stack_a = ps_rotate(*stack_a);
		ft_printf("ra\n");
	}
	else if (stack_a[0][1][1] == 3)
	{
		*stack_a = ps_rev_rotate(*stack_a);
		ft_printf("rra\n");
	}
	if (stack_a[0][0][1] == 2)
	{
		*stack_a = ps_swap(*stack_a);
		ft_printf("sa\n");
	}
}

static void	nb_sort_4(int ***stack_a, int ***stack_b)
{
	while (stack_a[0][0][1] < 4)
	{
		*stack_a = ps_rotate(*stack_a);
		ft_printf("ra\n");
	}
	ps_push(stack_a, stack_b);
	ft_printf("pb\n");
	nb_sort_3(stack_a);
	ps_push(stack_b, stack_a);
	ft_printf("pa\n");
}

static void	nb_sort_5(int ***stack_a, int ***stack_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		while (stack_a[0][0][1] < 4)
		{
			*stack_a = ps_rotate(*stack_a);
			ft_printf("ra\n");
		}
		ps_push(stack_a, stack_b);
		ft_printf("pb\n");
		i ++;
	}
	nb_sort_3(stack_a);
	if (stack_b[0][0][1] != 5)
	{
		*stack_b = ps_swap(*stack_b);
		ft_printf("sb\n");
	}
	ps_push(stack_b, stack_a);
	ft_printf("pa\n");
	ps_push(stack_b, stack_a);
	ft_printf("pa\n");
}

static void	finish_sort(int ***stack)
{
	while (stack[0][0][1] != 1)
	{
		*stack = ps_rotate(*stack);
		ft_printf("ra\n");
	}
}

void	ps_sort_nb3(int ***stack_a, int ***stack_b, int len)
{
	if (len == 3)
		nb_sort_3(stack_a);
	if (len == 4)
		nb_sort_4(stack_a, stack_b);
	if (len == 5)
		nb_sort_5(stack_a, stack_b);
	finish_sort(stack_a);
}
