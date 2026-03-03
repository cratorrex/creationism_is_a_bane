/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:48:20 by thtay             #+#    #+#             */
/*   Updated: 2026/03/02 19:48:21 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_stackLen(int **stack)
{
	int	len;

	len = 0;
	while (stack[len] != NULL && stack[len][1] != 0 
		&& len < (ft_arrlen((char **) stack) - 1))
	{
		len++;
		if (stack[len] == NULL)
			break ;
	}
	return (len);
}

static void	ps_push_nul(int ***stack, int ***dest)
{
	int	len;

	len = ps_stackLen(*stack);
	if (stack[0][len][1] == 0)
		len--;
	ft_printf ("%i\n", len);
	stack[0][len][0] = 0;
	stack[0][len][1] = 0;
	if (stack[0][len + 1] != NULL)
	{
		stack[0][len + 1][0] = 0;
		stack[0][len + 1][1] = 0;
	}
	if(len == 1 && dest[0][0][0] == stack[0][0][0])
	{
		stack[0][0][0] = 0;
		stack[0][0][1] = 0;
	}
}

//if empty, do nothing, wasted move :(
//update: uhh... f[*][*]k... i'm allowed to swear right?
void	ps_push(int ***stack, int ***stack_dest)
{
	int	len;

	len = ps_stackLen(*stack_dest);
	if (*stack[0][0] == 0)
		return ;
	while (len > 0)
	{
		len--;
		stack_dest[0][len + 1][0] = stack_dest[0][len][0];
		stack_dest[0][len + 1][1] = stack_dest[0][len][1];
	}
	stack_dest[0][0][0] = stack[0][0][0];
	stack_dest[0][0][1] = stack[0][0][1];
	*stack = ps_rotate(*stack);
	ps_push_nul(stack, stack_dest);
}

