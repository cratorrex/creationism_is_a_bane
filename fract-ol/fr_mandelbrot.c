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

void	fr_mandel2(float x, float y, t_fract_ol f)
{
	int			iter;
	t_coords	coords;

	iter = 0;
	coords.z = 0;
	coords.c = 0;
	while (iter < f.set_iter)
	{
		coords.z_r = pow(coords.z, 2) - pow(coords.c, 2) + x
			/ (0.2 * (f.resx) * (f.zoom));
		coords.c_r = (2 * coords.z * coords.c) + y / (0.2 * (f.resy)
				* (f.zoom));
		if (pow(coords.z_r, 2) + pow(coords.c_r, 2) > 4)
		{
			fr_colmap(f, x, y, iter);
			break ;
		}
		else
			fr_colmap_null(f, x, y);
		coords.z = coords.z_r;
		coords.c = coords.c_r;
		iter++;
	}
	return ;
}

void	fr_mandelbrot(float x, float y, t_fract_ol f)
{
	if (f.set_pow == 2)
		fr_mandel2(x, y, f);
}
