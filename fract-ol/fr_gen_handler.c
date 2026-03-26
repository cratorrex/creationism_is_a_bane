/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_gen_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:31:39 by thtay             #+#    #+#             */
/*   Updated: 2026/03/24 19:31:41 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr_colmap_null(t_fract_ol frx, double x, double y)
{
	int	bit;

	bit = (int)((y + (0.5 * frx.resy)) * frx.sl +
		(x + (0.5 * frx.resx) - 1) * 4);
	frx.img_data[bit] = 0;
	frx.img_data[bit + 1] = 0;
	frx.img_data[bit + 2] = 0;
	frx.img_data[bit + 3] = 0;
}

void	fr_colmap(t_fract_ol frx, double x, double y, int i)
{
	int	col;
	int	bit;

	bit = (int)((y + (0.5 * frx.resy)) * frx.sl +
		(x + (0.5 * frx.resx) - 1) * 4);
	col = (int)(i*i) | 128;
	if (frx.col == 1)
		col = (348 << i) / 5;
	if (frx.col == 2)
		col = (int)(x * y / i) | 128;
	if (frx.col == 3)
		col = (int)(250 + i * i * i) & 4144959;
	if (frx.col == 4)
		col = 127 + pow(255 * i + 36 * i + 1, 1.3) * 128;
	if (frx.col == 5)
		col = (int)((frx.off_x + frx.off_y) * i) | 128;
	frx.img_data[bit] = col;
	frx.img_data[bit + 1] = col / 8;
	frx.img_data[bit + 2] = col / 64;
	frx.img_data[bit + 3] = col / 256;
}

void	fr_gen(t_fract_ol *frx)
{
	if (frx->set_fract == 1)
	{
		fr_mandelbrot(*frx);
	}
	if (frx->set_fract == 2)
	{
		//fr_julia(*frx);
	}
	mlx_put_image_to_window(frx->mlx, frx->window, frx->image, 0, 0);
}
