/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:08:20 by thtay             #+#    #+#             */
/*   Updated: 2026/03/24 18:08:21 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr_mandel2(double x, double y, t_fract_ol f)
{
	int			iter;
	t_coords	coords;

	iter = 0;
	coords.z = 0;
	coords.c = 0;
	coords.con_z = (0.2 * (f.resx) * (f.zoom));
	coords.con_c = (0.2 * (f.resy) * (f.zoom));
	fr_colmap_null(f, x, y);
	while (iter < f.set_iter)
	{
		coords.z_r = coords.z * coords.z - coords.c * coords.c + (x + f.off_x)
			/ coords.con_z;
		coords.c_r = (2 * coords.z * coords.c) + (y + f.off_y) / coords.con_c;
		if (coords.z_r * coords.z_r + coords.c_r * coords.c_r > 4)
		{
			fr_colmap(f, x, y, iter);
			break ;
		}
		coords.z = coords.z_r;
		coords.c = coords.c_r;
		iter++;
	}
	return ;
}

void	fr_mandelbrot(t_fract_ol f)
{
	double	x;
	double	y;

	if (f.set_pow == 2)
	{
		x = 0.5 * f.resx;
		while (x > -0.5 * f.resx)
		{
			y = 0.5 * f.resy;
			while (y > (-0.5 * f.resy))
			{
				fr_mandel2(x, y, f);
				y--;
			}
			x--;
		}
	}
}
