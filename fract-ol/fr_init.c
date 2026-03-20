/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:14 by thtay             #+#    #+#             */
/*   Updated: 2026/03/12 16:36:16 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr_init(t_fract_ol *frx)
{
	frx->mlx = mlx_init();
	if (!frx->mlx)
		exit (1);
	frx->window = mlx_new_window(frx->mlx, 500, 500, "Hello World!");
	if (!frx->window)
		fr_init_e (frx, 1);
	frx->image = mlx_new_image(frx->mlx, 20, 20);
	if (!frx->image)
		fr_init_e (frx, 2);


}
