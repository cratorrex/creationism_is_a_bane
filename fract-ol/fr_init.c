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

static void	fr_init_mlx(t_fract_ol *frx)
{
	frx->mlx = mlx_init();
	if (!frx->mlx)
		exit (1);
	frx->window = mlx_new_window(frx->mlx, frx->resx, frx->resy,
			"Fractol");
	if (!frx->window)
		fr_init_e (frx, 1);
	frx->image = mlx_new_image(frx->mlx, frx->resx, frx->resy);
	if (!frx->image)
		fr_init_e (frx, 2);
	frx->img_data = mlx_get_data_addr(frx->image, &frx->bpp,
			&frx->sl, &frx->endian);
	if (!frx->img_data)
		fr_init_e (frx, 3);
}

void	fr_init(t_fract_ol *frx, char **vec)
{
	if (ft_strnstr(vec[1], "mandelbrot", 10) != NULL
		&& ft_strlen(vec[1]) == 10)
	{
		frx->set_fract = 1;
		fr_vec_options(frx, vec[2]);
	}
	else if (ft_strnstr(vec[1], "julia", 5) != NULL && ft_strlen(vec[1]) == 5)
	{
		frx->set_fract = 2;
		frx->jul_x = 0;
		frx->jul_y = 0;
		if (ft_atod_e(vec[2], &frx->jul_x) || ft_atod_e(vec[3], &frx->jul_y))
			fr_options(0);
		fr_vec_options(frx, vec[4]);
	}
	else if (ft_strnstr(vec[1], "tricorn", 7) != NULL
		&& ft_strlen(vec[1]) == 7)
	{
		frx->set_fract = 3;
		fr_vec_options(frx, vec[2]);
	}
	else
		fr_options(0);
	fr_init_mlx(frx);
}
