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

void	fr_options(void)
{
	ft_printf("=== FRACTOL ===\nThis program is designed to display some\
 fractals given specific arguments.\n./fractol {FRACTAL} [OPTIONS]\n\n");
	ft_printf("-- FRACTAL --\nmandelbrot\t\tDisplays the mandelbrot\
 set of fractals.\n\
julia {x} {y}\t\tDisplays the julia set of fractals given X and Y \
as decimals.\n\n");
	ft_printf("-- OPTIONS --\nThis must be passed as one argument, \
and all numbers must be a positive integer greater than 0.\n\
Example invocation: ./fractol mandelbrot i14x500p3\n\n\
i\t\tDefault: \"i32\"\t  Initial iterations to render.\n\
p\t\tDefault: \"p2\"\t  Power of function. TBI\n\
r | x y\t\tDefault: \"r500\"\
\t  ResXY of window. If r is not given, x and y are set individually.\n\
c\t\tDefault: \"c0\"\t  Colour Scheme to be used. 0-5\n\
z\t\tDefault: \"z1\"\t  The initial zoom of the viewport.\n\n");
	ft_printf("-- INTERACTION KEYBINDS --\n\
ESC | Q\t\tQuit\nO\t\tReturn to Origin (xy 0,0)\n\
C\t\tCycle colour schemes (c0 to c5)\n\n\
W A S D\t\tPans around the screen in steps of 20 pixels\n\
+ (=) | -\tZooms in(+) or out(-) by step 1.25 or 0.8\n\
. (>) | , (<)\t+ or - 1 iteration to the fractal (Min 0, blank screen)\n\
Arrow Keys\tAlters the Julia fractal in step 0.01");
}

static void	fr_set_options(t_fract_ol *frx, char *vec)
{
	if (ft_strchr(vec, 'i') != NULL)
		frx->set_iter = ft_atoi(ft_strchr(vec, 'i') + 1);
	if (ft_strchr(vec, 'p') != NULL)
		frx->set_pow = ft_atoi(ft_strchr(vec, 'p') + 1);
	if (ft_strchr(vec, 'c') != NULL)
		frx->col = ft_atoi(ft_strchr(vec, 'c') + 1);
	if (ft_strchr(vec, 'z') != NULL)
		frx->zoom = ft_atoi(ft_strchr(vec, 'z') + 1);
	if (ft_strchr(vec, 'r') != NULL)
	{
		frx->resx = ft_atoi(ft_strchr(vec, 'r') + 1);
		frx->resy = frx->resx;
	}
	else
	{
		if (ft_strchr(vec, 'x') != NULL)
			frx->resx = ft_atoi(ft_strchr(vec, 'x') + 1);
		if (ft_strchr(vec, 'y') != NULL)
			frx->resy = ft_atoi(ft_strchr(vec, 'y') + 1);
	}
}

static void	fr_vec_options(t_fract_ol *frx, char *vec)
{
	frx->set_iter = 32;
	frx->set_pow = 2;
	frx->zoom = 1;
	frx->resx = 500;
	frx->resy = 500;
	frx->col = 0;
	frx->off_x = 0.5;
	frx->off_y = 0.5;
	if (vec)
		fr_set_options(frx, vec);
}

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
	if (ft_strnstr(vec[1], "mandelbrot", 10) != NULL)
	{
		frx->set_fract = 1;
		fr_vec_options(frx, vec[2]);
	}
	else if (ft_strnstr(vec[1], "julia", 5) != NULL)
	{
		frx->set_fract = 2;
		if (ft_atod_e(vec[2], &frx->jul_x) || ft_atod_e(vec[3], &frx->jul_y))
		{
			fr_options();
			exit(0);
		}
		fr_vec_options(frx, vec[4]);
	}
	else
	{
		fr_options();
		exit(0);
	}
	fr_init_mlx(frx);
}
