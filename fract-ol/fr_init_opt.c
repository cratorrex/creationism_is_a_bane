/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_init_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:28:49 by thtay             #+#    #+#             */
/*   Updated: 2026/04/01 16:28:50 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr_options(void)
{
	ft_printf("=== FRACTOL ===\nThis program is designed to display some\
 fractals given specific arguments.\n./fractol {FRACTAL} [OPTIONS]\n\n");
	ft_printf("-- FRACTAL --\nmandelbrot\t\tDisplays the mandelbrot\
 set of fractals. Can display the tricorn set at negative power.\n\
julia {x} {y}\t\tDisplays the julia set of fractals given X and Y \
as decimals.\n\n");
	ft_printf("-- OPTIONS --\nThis must be passed as one argument, \
and all numbers are parsed as integers.\n\
Example invocation: ./fractol mandelbrot i14x500p3\n\n\
i\t\tDefault: \"i32\"\t  Initial iterations to render. (Min 1)\n\
p\t\tDefault: \"p2\"\t  Power of function.\n\
r | x y\t\tDefault: \"r500\"\
\t  ResXY of window. If r is not given, x and y are set individually.\n\
c\t\tDefault: \"c0\"\t  Colour Scheme to be used. 0-5\n\
z\t\tDefault: \"z1\"\t  The initial zoom of the viewport.\n\
m\t\tDefault: \"m20\"\t  Sets the amount of step for panning the fractal \
in pixels.\n\
s\t\tDefault: \"s100\"\t  Sets the amount of step for the Julia fractal \
(Divided by 10000).\n\n");
	fr_options_2();
}

void	fr_options_2(void)
{
	ft_printf("-- INTERACTION KEYBINDS --\n\
ESC | Q\t\tQuit\nO\t\tReturn to Origin (xy 0,0)\n\
C\t\tCycle colour schemes (c0 to c5)\n\
Z\t\tCycles step for the Julia fractal by *10 (MOD 9999 /10000)\n\
X\t\tCycles step for panning the fractal by *5 \
(MOD 499)\n\
P\t\tCycles Power of the Fractal wherever applicable\n\n\
W A S D\t\tPans around the screen in steps of 20 (default) pixels\n\
+ (=) | -\tZooms in(+) or out(-) by step 1.25 or 0.8\n\
. (>) | , (<)\t+ or - 1 iteration to the fractal (Min 1)\n\
Arrow Keys\tAlters the Julia fractal in step 0.01 (default)\n");
}

static void	fr_set_options_2(t_fract_ol *frx, char *vec)
{
	if (ft_strchr(vec, 'm') != NULL)
		frx->pan = ft_atoi(ft_strchr(vec, 'm') + 1);
	if (ft_strchr(vec, 's') != NULL)
		frx->jpan = ft_atoi(ft_strchr(vec, 's') + 1);
	if (!ft_strchr(vec, 'i') && !ft_strchr(vec, 'p') && !ft_strchr(vec, 'c')
		&& !ft_strchr(vec, 'c') && !ft_strchr(vec, 'z')
		&& !ft_strchr(vec, 'r') && !ft_strchr(vec, 'x')
		&& !ft_strchr(vec, 'y') && !ft_strchr(vec, 'm')
		&& !ft_strchr(vec, 's'))
	{
		fr_options();
		exit (1);
	}
}

static void	fr_set_options(t_fract_ol *frx, char *vec)
{
	if (ft_strchr(vec, 'i') != NULL)
		frx->set_iter = fmax(ft_atoi(ft_strchr(vec, 'i') + 1), 1);
	if (ft_strchr(vec, 'p') != NULL)
		frx->set_pow = ft_atoi(ft_strchr(vec, 'p') + 1);
	if (ft_strchr(vec, 'c') != NULL)
		frx->col = fmin(5, fmax(0, ft_atoi(ft_strchr(vec, 'c') + 1)));
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
	fr_set_options_2(frx, vec);
}

void	fr_vec_options(t_fract_ol *frx, char *vec)
{
	frx->set_iter = 32;
	frx->set_pow = 2;
	frx->zoom = 1;
	frx->resx = 500;
	frx->resy = 500;
	frx->col = 0;
	frx->off_x = 0.5;
	frx->off_y = 0.5;
	frx->pan = 20;
	frx->jpan = 100;
	if (vec)
		fr_set_options(frx, vec);
}
