/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug_dsp_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:13:28 by thtay             #+#    #+#             */
/*   Updated: 2026/02/13 17:13:30 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_dsp2(char *instr, int ***stack_a, int ***stack_b);

static void	print_stacks(int **stack_a, int **stack_b)
{
	int	i;

	i = 0;
	while (stack_a[i] && stack_b[i])
	{
		if (stack_a[i])
			ft_printf("%i [A%i] |", stack_a[i][0], stack_a[i][1]);
		if (stack_b[i])
			ft_printf(" %i [B%i]\n", stack_b[i][0], stack_b[i][1]);
		i++;
	}
}

void	ps_dsp(char *instr, int ***stack_a, int ***stack_b)
{
	if (instr[0] == 's')
	{
		if (instr[1] == 's')
		{
			*stack_a = ps_swap(*stack_a);
			*stack_b = ps_swap(*stack_b);
		}
		if (instr[1] == 'a')
			*stack_a = ps_swap(*stack_a);
		if (instr[1] == 'b')
			*stack_b = ps_swap(*stack_b);
	}
	if (instr[0] == 'p')
	{
		if (instr[1] == 'a')
			ps_push(stack_b, stack_a);
		if (instr[1] == 'b')
			ps_push(stack_a, stack_b);
	}
	ps_dsp2(instr, stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
}

static void	ps_dsp2(char *instr, int ***stack_a, int ***stack_b)
{
	if (instr[0] == 'r')
	{
		if (instr[1] == 'r' && instr[2] == 'r')
		{
			*stack_a = ps_rev_rotate(*stack_a);
			*stack_b = ps_rev_rotate(*stack_b);
			return ;
		}
		if (instr[1] == 'r' && instr[2] == 'a')
			*stack_a = ps_rev_rotate(*stack_a);
		if (instr[1] == 'r' && instr[2] == 'b')
			*stack_b = ps_rev_rotate(*stack_b);
		if (instr[1] == 'r')
		{
			*stack_a = ps_rotate(*stack_a);
			*stack_b = ps_rotate(*stack_b);
		}
		if (instr[1] == 'a')
			*stack_a = ps_rotate(*stack_a);
		if (instr[1] == 'b')
			*stack_b = ps_rotate(*stack_b);
	}
}
