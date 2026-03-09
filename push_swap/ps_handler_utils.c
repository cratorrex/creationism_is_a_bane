/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_handler_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:06:06 by thtay             #+#    #+#             */
/*   Updated: 2026/02/27 16:06:08 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rerank(int ***stack, int len, int len_i)
{
	int	i;
	int	k;
	int	max;
	int	min;

	min = INT_MIN;
	max = INT_MAX;
	i = -1;
	while (++i < len && len_i)
	{
		if (stack[0][i][0] < max && stack[0][i][0] > min)
		{
			max = stack[0][i][0];
			k = i;
		}
		if (i == len - 1)
		{
			i = -1;
			stack[0][k][1] = len - (len_i-- - 1);
			min = stack[0][k][0];
			max = INT_MAX;
		}
	}
}

// M|1 = Init, M|2 = Recreate
int	**ps_r_init_stack(int **stack, int mode)
{
	int	**ret;
	int	i;

	i = 0;
	ret = NULL;
	if (mode & 1)
	{
		ret = malloc((sizeof (int *)) * (ft_arrlen((char **)stack) + 1));
		if (!ret)
			return (stack);
		while (i < ft_arrlen((char **)stack))
		{
			ret[i] = malloc(2 * sizeof (int));
			ret[i][0] = 0;
			ret[i++][1] = 0;
		}
		ret[i] = NULL;
	}
	i = 0;
	if (mode & 2)
		while (i < ft_arrlen((char **)stack))
			free(stack[i++]);
	if (!ret)
		return (stack);
	return (ret);
}

//idfk why i decided this was a good idea
//but basically
// Q1 `pa / pb`
// Q2 `sa / sb / ss`
// Q3 `ra / rb` /// `rr` // `rra / rrb` // `rrr`
int	isinstruction(char *buffer)
{
	char	cha;

	cha = '\n';
	if (buffer[0] == 'p')
		if (buffer[1] == 'a' || buffer[1] == 'b')
			if (buffer[2] == cha)
				return (1);
	if (buffer[0] == 's')
		if (buffer[1] == 'a' || buffer[1] == 'b' || buffer[1] == 's')
			if (buffer[2] == cha)
				return (1);
	if (buffer[0] == 'r')
	{
		if (buffer[1] == 'a' || buffer[1] == 'b' && buffer[2] == cha)
			return (1);
		if (buffer[1] == 'r')
		{
			if (buffer[2] == cha)
				return (1);
			if (buffer[2] == 'a' || buffer[2] == 'b' || buffer[2] == 'r')
				if (buffer[3] == cha)
					return (1);
		}
	}
	return (0);
}
