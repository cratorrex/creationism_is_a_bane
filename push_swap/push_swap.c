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
static void	print_e(char error)
{
	if (((error & 128) | (error & 64)) & !(error & 1))
		return ;
	ft_printf("Error\n");
}

//sending in [[0, 1], [1, 2], [5, 10], ...] <-- [[Number, Rank], ...]
static void	del_init(char **init)
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
	char	**init;
	char	error;

	error = ERROR_TYPE & 1;
	init = init_params(params, count, &error);
	ft_printf("%i", error);
	if (!init || error > 1)
	{
		print_e(error);
		if (init)
			del_init(init);
		return (0);
	}
	del_init(init);
}
