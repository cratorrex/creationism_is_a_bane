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

static void	manual_solve(int ***stack_a, int ***stack_b)
{
	char	*buf;
	int		rbytes;

	buf = malloc(sizeof (char) * 5);
	while (!(order_pass(*stack_a, 0) & 128))
	{
		ft_bzero(buf, 5);
		rbytes = read(1, buf, 5);
		if (isInstruction(buf))
			ps_dsp(buf, stack_a, stack_b);
		while (rbytes > 0 && !(ft_memchr(buf, 0, 5)
				|| ft_memchr(buf, '\n', 5)))
		{
			ft_bzero(buf, 5);
			rbytes = read(1, buf, 5);
		}
	}
	return (free(buf));
}

//we'll start off here. given our init[i][2] array, we may need more.
//but this is what we'll feed in to start off.
//if we have DISPLAY_MOVES macro on, then we'll pass to that.
int	**ps_start(int **stack_a)
{
	t_list	list_a;
	t_list	list_b;
	int		**stack_b;

	stack_b = ps_r_init_stack(stack_a, 1);
	if (DISPLAY_MOVES > 0)
	{
		manual_solve(&stack_a, &stack_b);
	}
	free (ps_r_init_stack(stack_b, 2));
	return (stack_a);
}
