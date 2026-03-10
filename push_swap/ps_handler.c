/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:25:53 by thtay             #+#    #+#             */
/*   Updated: 2026/02/12 16:25:56 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("\n");
}

//does not rerank cus im a buffoon- wait a sec~
static void	ps_dsp_solve(int ***stack_a, int ***stack_b)
{
	char	*buf;
	int		rbytes;
	int		mc;

	mc = 0;
	buf = malloc(sizeof (char) * 5);
	while (!(order_pass(*stack_a, 0) & 128) || (*stack_b[0][0]))
	{
		ft_bzero(buf, 5);
		rbytes = read(1, buf, 5);
		if (isinstruction(buf))
		{
			ps_dsp(buf, stack_a, stack_b);
			mc ++;
		}
		while (rbytes > 0 && !(ft_memchr(buf, 0, 5)
				|| ft_memchr(buf, '\n', 5)))
		{
			ft_bzero(buf, 5);
			rbytes = read(1, buf, 5);
		}
	}
	ft_printf("Moves taken: %i.\n", mc);
	return (free(buf));
}

static void	ps_sort(int ***stack_a, int ***stack_b)
{
	int	n;

	n = ft_arrlen((char **) *stack_a);
	if (n == 2)
	{
		ps_swap(*stack_a);
		ft_printf("sa\n");
		return ;
	}
	ps_rerank(stack_a, n, n);
	if (n > 2 && n < 6)
		ps_sort_nb3(stack_a, stack_b, n);
	else
		ps_sort_radix(stack_a, stack_b, n);
}

//we'll start off here. given our init[i][2] array, we may need more.
//but this is what we'll feed in to start off.
//if we have DISPLAY_MOVES macro on, then we'll pass to that.
//
//otherwise let's send in to the sorts
int	**ps_start(int **stack_a)
{
	int		**stack_b;

	stack_b = ps_r_init_stack(stack_a, 1);
	if (DISPLAY_MOVES & 1)
	{
		ps_dsp_solve(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
	}
	else
		ps_sort(&stack_a, &stack_b);
	free (ps_r_init_stack(stack_b, 2));
	return (stack_a);
}
