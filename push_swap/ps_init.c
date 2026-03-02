/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:00:40 by thtay             #+#    #+#             */
/*   Updated: 2026/02/20 17:00:42 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_atoi_e >> ERROR | 2
static void	free_params(char **params)
{
	if (params)
	{
		while (*params)
		{
			free(*params);
			params ++;
		}
	}
}

static char	**init_pass(char **params, int count)
{
	int		i;
	char	*join;
	char	**split;

	join = "";
	i = 1;
	while (params[i] && i < count)
	{
		join = ft_strjoin_free(join, params[i]);
		join = ft_strjoin_free(join, " ");
		i++;
	}
	split = ft_split_two(join, ' ', '\n');
	free (join);
	return (split);
}

int	order_pass(int **params, int error)
{
	int	i;
	int	j;
	int	order;
	int	duplic;

	i = 1;
	j = 0;
	order = 1;
	duplic = 0;
	while (params[i])
	{
		if (params[i][0] < params[i - 1][0])
			order = 0;
		while (j < i)
		{
			if (params[j][0] == params[i][0])
				duplic = 1;
			j ++;
		}
		j = 0;
		i ++;
	}
	error = error | (order * 128) | (duplic * 4);
	return (error);
}

int	**init_params(char **params, int count, int *error)
{
	int		**init;
	int		i;

	i = 0;
	params = init_pass(params, count);
	count = ft_arrlen(params);
	init = malloc((sizeof (int *)) * (count + 1));
	if (!init)
	{
		if (params)
			free_params(params);
		return (NULL);
	}
	while (i < count)
	{
		init[i] = malloc(sizeof (int) * 2);
		init[i][0] = ft_atoi_e(params[i], error);
		init[i][1] = i + 1;
		ft_printf("%i [%i]\n", init[i][0], init[i][1]);
		i++;
	}
	init[i] = NULL;
	free_params(params);
	free(params);
	return (init);
}
