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

void	fr_options(int e)
{
	ft_printf("=== FRACTOL ===\nThis program is designed to display some\
 fractals given specific arguments.\n./fractol {FRACTAL} [OPTIONS]\n\n");
	ft_printf("-- FRACTAL --\nmandelbrot\t\tDisplays the mandelbrot\
 set of fractals.\n\
julia {x} {y}\t\tDisplays the julia set of fractals given X and Y \
as decimals.\n\
tricorn\t\t\tDisplays the tricorn set fractal.\n\n");
	ft_printf("-- OPTIONS --\nThis must be passed as one argument, \
and all numbers are parsed as integers.\n\
Example invocation: ./fractol mandelbrot i14r500p3\n\n\
i\t\tDefault: \"i32\"\t  Initial iterations to render. (Min 1)\n\
p\t\tDefault: \"p2\"\t  Power of function.\n\
r\t\tDefault: \"r500\"\t  ResXY of window. (Min 1)\n\
D\t\tDefault: \"D0\"\t  Prints the viewport statistics if (> 1).\n");
	fr_options_2();
	exit (e);
}

void	fr_options_2(void)
{
	ft_printf("\n-- INTERACTION KEYBINDS --\n\
/ (?) | V\tPrints the Keybinds again.\n\
TAB\t\tToggles printing of the viewport statistics on any keypress.\n\
ESC   | Q\tQuit\n\nO\t\tReturn to Origin (xy 0,0)\n\
C\t\tCycle colour schemes (c0 to c5)\n\
Z\t\tCycles step for the Julia fractal by *10 (MOD 9999 /10000)\n\
X\t\tCycles step for panning the fractal by *5 \
(MOD 499)\n\
P\t\tCycles Power of the Fractal wherever applicable\n\n\
Arrow Keys\tPans around the screen in steps of 20 (default) pixels\n\
W A S D\t\tAlters the Julia fractal in step 0.01 (default)\n\
= (+) | -\tZooms in(+) or out(-) by step 1.25 or 0.8\n\
. (>) | , (<)\t+ or - 1 iteration to the fractal (Min 1)\n\n");
}

static void	fr_set_options_2(t_fract_ol *frx, char *vec)
{
	int	res;

	if (ft_strchr(vec, 'p') != NULL)
	{
		if (!ft_atoi_e(ft_strchr(vec, 'p') + 1, &res))
			frx->set_pow = res;
		else
			fr_options(1);
	}
	if (ft_strchr(vec, 'i') != NULL)
	{
		if (!ft_atoi_e(ft_strchr(vec, 'i') + 1, &res) && res >= 1)
			frx->set_iter = res;
		else
			fr_options(1);
	}
	if (!ft_strchr(vec, 'i') && !ft_strchr(vec, 'p')
		&& !ft_strchr(vec, 'r') && !ft_strchr(vec, 'D'))
	{
		fr_options(1);
	}
}

static void	fr_set_options(t_fract_ol *frx, char *vec)
{
	int	res;

	if (ft_strchr(vec, 'r') != NULL)
	{
		if (!ft_atoi_e(ft_strchr(vec, 'r') + 1, &res) && res >= 1)
		{
			frx->resx = res;
			frx->resy = frx->resx;
		}
		else
			fr_options(1);
	}
	if (ft_strchr(vec, 'D') != NULL)
	{
		if (!ft_atoi_e(ft_strchr(vec, 'D') + 1, &res) && res >= 0)
			frx->debug = res;
		else
			fr_options(1);
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
	frx->off_x = 0;
	frx->off_y = 0;
	frx->pan = 20;
	frx->jpan = 100;
	frx->debug = 0;
	if (vec)
		fr_set_options(frx, vec);
}
