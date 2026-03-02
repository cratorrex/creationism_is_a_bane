/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:26:03 by thtay             #+#    #+#             */
/*   Updated: 2026/02/12 16:26:04 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Errors (check if div|b)
// `128` Sorted
// `064` No Input Given
// ------------
// `004` Duplicates
// `002` Invalid Integer(s) { incl >INT_MAX, cannot parse }
// ------------
// `001` ERROR_TYPE macro bit (check & 1)
// ------------
// `000` No Errors, so this function should not run.
static int	print_e(int error)
{
	if (((error == 128) || (error == 64)) & !(error & 1))
		return (0);
	ft_printf("Error\n");
	if (error & 1)
	{
		ft_printf("Code: %i\n", error);
		if (error & 2)
			ft_printf("Invalid Integer Argument.\n");
		if (error & 4)
			ft_printf("Duplicates Found. (Invalid Integers\
 may be treated as \"0\".)\n");
		if (error & 64)
			ft_printf("No Input Given. Stop.\n");
		if (error & 128)
			ft_printf("String has already been sorted.\n");
	}
	return (0);
}

//sending in [[0, 1], [1, 2], [5, 10], ...] <-- [[Number, Rank], ...]
static void	del_init(int **init)
{
	int	i;

	i = 0;
	while (init[i])
	{
		ft_bzero(init[i], 2);
		free(init[i]);
		i++;
	}
	free(init);
}

int	main(int count, char **params)
{
	int		**init;
	int		error;

	error = ERROR_TYPE & 1;
	if (count == 1)
		return (print_e(64 | ERROR_TYPE));
	init = init_params(params, count, &error);
	error = order_pass(init, error);
	if (!init || error > 1)
	{
		print_e(error);
		if (init)
			del_init(init);
		return (0);
	}
	init = ps_start(init);
	del_init(init);
}
