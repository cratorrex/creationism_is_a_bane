/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:25:23 by thtay             #+#    #+#             */
/*   Updated: 2026/03/26 16:25:24 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fr_julian(double x, double y, t_fract_ol f)
{
	int			iter;
	t_coords	cds;
	double		power;

	iter = 0;
	power = f.set_pow;
	cds.zx = ((x + f.off_x) / f.resx) / (0.2 * f.zoom);
	cds.zy = ((y + f.off_y) / f.resy) / (0.2 * f.zoom);
	fr_colmap_null(f, x, y);
	while (iter < f.set_iter)
	{
		cds.z_r = pow(cds.zx * cds.zx + cds.zy * cds.zy, power / 2)
			* cos(power * atan2(cds.zy, cds.zx)) + f.jul_x;
		cds.zy = pow((cds.zx * cds.zx + cds.zy * cds.zy), power / 2)
			* sin(power * atan2(cds.zy, cds.zx)) + f.jul_y;
		cds.zx = cds.z_r;
		if (cds.zx * cds.zx + cds.zy * cds.zy > power * power)
		{
			fr_colmap(f, x, y, iter);
			break ;
		}
		iter ++;
	}
	return ;
}

static void	fr_julia2(double x, double y, t_fract_ol f)
{
	int			iter;
	t_coords	coords;

	iter = 0;
	coords.zx = ((x + f.off_x) / f.resx) / (0.2 * f.zoom);
	coords.zy = ((y + f.off_y) / f.resy) / (0.2 * f.zoom);
	fr_colmap_null(f, x, y);
	while (iter < f.set_iter)
	{
		coords.z_r = coords.zx * coords.zx - coords.zy * coords.zy;
		coords.zy = 2 * coords.zx * coords.zy - (f.jul_y);
		coords.zx = coords.z_r + (f.jul_x);
		if (coords.zx * coords.zx + coords.zy * coords.zy > 4)
		{
			fr_colmap(f, x, y, iter);
			break ;
		}
		iter ++;
	}
	return ;
}

void	fr_julia(t_fract_ol f)
{
	double	x;
	double	y;

	x = 0.5 * f.resx;
	while (x > -0.5 * f.resx)
	{
		y = 0.5 * f.resy;
		while (y > (-0.5 * f.resy))
		{
			if (f.set_pow == 2)
				fr_julia2(x, y, f);
			else
				fr_julian(x, y, f);
			y--;
		}
		x--;
	}
}
