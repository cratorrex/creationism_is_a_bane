/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:40:13 by thtay             #+#    #+#             */
/*   Updated: 2026/03/13 16:40:15 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fr_kill(t_fract_ol *p)
{
	mlx_destroy_image(p->mlx, p->image);
	mlx_clear_window(p->mlx, p->window);
	mlx_destroy_window(p->mlx, p->window);
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	exit (0);
}

int	fr_init_e(t_fract_ol *p, int step)
{
	if (step > 2)
		mlx_destroy_image(p->mlx, p->image);
	if (step > 1)
		mlx_destroy_window(p->mlx, p->window);
	if (step > 0)
		mlx_destroy_display(p->mlx);
	exit (1);
}
