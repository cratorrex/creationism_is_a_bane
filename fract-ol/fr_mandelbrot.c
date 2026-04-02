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

static void	fr_multibrot(double x, double y, t_fract_ol f)
{
	int			iter;
	t_coords	cds;

	iter = 0;
	cds.z = 0;
	cds.c = 0;
	cds.con_z = (0.2 * (f.resx) * (f.zoom));
	cds.con_c = (0.2 * (f.resy) * (f.zoom));
	fr_colmap_null(f, x, y);
	while (iter < f.set_iter)
	{
		cds.z_r = pow(cds.z * cds.z + cds.c * cds.c, f.set_pow / 2.0f)
			* cos(f.set_pow * atan2(cds.c, cds.z)) + (x + f.off_x) / cds.con_z;
		cds.c_r = pow(cds.z * cds.z + cds.c * cds.c, f.set_pow / 2.0f)
			* sin(f.set_pow * atan2(cds.c, cds.z)) + (y + f.off_y) / cds.con_c;
		if (cds.z_r * cds.z_r + cds.c_r * cds.c_r > 4)
		{
			fr_colmap(f, x, y, iter);
			break ;
		}
		cds.z = cds.z_r;
		cds.c = cds.c_r;
		iter++;
	}
	return ;
}

static void	fr_mandel_1(double x, double y, t_fract_ol f)
{
	int			iter;
	t_coords	cds;

	iter = 0;
	cds.con_z = (0.2 * (f.resx) * (f.zoom));
	cds.con_c = (0.2 * (f.resy) * (f.zoom));
	cds.z = 0;
	cds.c = 0;
	fr_colmap_null(f, x, y);
	while (iter < f.set_iter)
	{
		cds.z_r = (cds.z) + ((x + f.off_x) / cds.con_z);
		cds.c = -1.0f * ((cds.c) - ((y + f.off_y) / cds.con_c));
		if (cds.z * cds.z - cds.c * cds.c > 4)
		{
			fr_colmap(f, x, y, iter);
			break ;
		}
		cds.z = cds.z_r;
		iter++;
	}
	return ;
}

void	fr_mandel2(double x, double y, t_fract_ol f)
{
	int			iter;
	t_coords	cds;

	iter = 0;
	cds.z = 0;
	cds.c = 0;
	cds.con_z = (0.2 * (f.resx) * (f.zoom));
	cds.con_c = (0.2 * (f.resy) * (f.zoom));
	fr_colmap_null(f, x, y);
	while (iter < f.set_iter)
	{
		cds.z_r = cds.z * cds.z - cds.c * cds.c + (x + f.off_x) / cds.con_z;
		cds.c_r = (f.set_pow * cds.z * cds.c) + (y + f.off_y) / cds.con_c;
		if (cds.z_r * cds.z_r + cds.c_r * cds.c_r > 4)
		{
			fr_colmap(f, x, y, iter);
			break ;
		}
		cds.z = cds.z_r;
		cds.c = cds.c_r;
		iter++;
	}
	return ;
}

void	fr_mandelbrot(t_fract_ol f)
{
	double	x;
	double	y;

	x = 0.5 * f.resx;
	while (x > -0.5 * f.resx)
	{
		y = 0.5 * f.resy;
		while (y > (-0.5 * f.resy))
		{
			if (f.set_pow == 2 || f.set_pow == -2)
				fr_mandel2(x, y, f);
			else if (f.set_pow == -1)
				fr_mandel_1(x, y, f);
			else
				fr_multibrot(x, y, f);
			y--;
		}
		x--;
	}
}
