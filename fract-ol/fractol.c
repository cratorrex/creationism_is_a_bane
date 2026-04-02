/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:33:09 by thtay             #+#    #+#             */
/*   Updated: 2026/02/05 16:33:12 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void *mlx = mlx_init();

static int	mouse(int key, int x, int y, t_fract_ol *p)
{
	if (key == 4)
	{
		p->off_x *= 1.25;
		p->off_y *= 1.25;
		p->zoom = p->zoom * 1.25;
	}
	if (key == 5)
	{
		p->off_x *= 0.8;
		p->off_y *= 0.8;
		p->zoom = p->zoom * 0.8;
	}
	p->off_x = p->off_x + ((x - 0.5 * p->resx) / 2);
	p->off_y = p->off_y + ((y - 0.5 * p->resy) / 2);
	fr_gen(p);
	return (0);
}

//esc = 65307
// wasd = 119 97 115 100
// o = 111 (origin)
// c = 99 (colour)
// - = = 45 61 (zoom)
// , . = 44 46 (iter) (min1)
//
//
//17 is kill window
//shorten to one var void *p
//segf needs loarge struct cus fges
static void	keyboard_movement(int key, t_fract_ol *p)
{
	if (key == XK_w)
		p->off_y -= p->pan;
	if (key == XK_s)
		p->off_y += p->pan;
	if (key == XK_a)
		p->off_x -= p->pan;
	if (key == XK_d)
		p->off_x += p->pan;
	if (key == XK_comma || key == XK_period)
		p->set_iter = fmax(p->set_iter + (key - 45), 1);
	if (key == XK_Up || key == XK_Down)
		p->jul_y += (65363 - key) * 0.0001 * p->jpan;
	if (key == XK_Left || key == XK_Right)
		p->jul_x += (key - 65362) * 0.0001 * p->jpan;
	if (key == XK_z)
		p->jpan = fmax(1, (p->jpan * 10) % 9999);
	if (key == XK_x)
		p->pan = fmax(4, ((p->pan * 5) % 499));
	if (key == XK_p && p->set_fract == 1)
		p->set_pow = (p->set_pow + 3) % 9 - 2;
	if (key == XK_p && p->set_fract == 2)
		p->set_pow = (p->set_pow + 6) % 11 - 5;
	if (key == XK_p && p->set_fract == 3)
		p->set_pow = -2;
}

static int	keyboard(int key, t_fract_ol *p)
{
	if (key == 0xFF1B || key == 113)
		fr_kill(p);
	if (key == XK_equal)
	{
		p->off_x *= 1.25;
		p->off_y *= 1.25;
		p->zoom = p->zoom * 1.25;
	}
	if (key == XK_minus)
	{
		p->off_x *= 0.8;
		p->off_y *= 0.8;
		p->zoom = p->zoom * 0.8;
	}
	if (key == XK_o)
	{
		p->off_x = 0;
		p->off_y = 0;
		p->zoom = 1;
	}
	if (key == XK_c)
		p->col = (p->col + 1) % 6;
	keyboard_movement(key, p);
	fr_gen(p);
	return (0);
}

// colmaps
// (63<<iter)/5
// 127+pow(255*iter+36*iter+1,1.5)*128
int	main(int count, char **vec)
{
	t_fract_ol	frx;

	if (count < 2 || count > 5)
	{
		fr_options();
		exit (0);
	}
	fr_init(&frx, vec);
	fr_gen(&frx);
	mlx_key_hook(frx.window, keyboard, &frx);
	mlx_loop_hook(frx.mlx, NULL, 0);
	mlx_mouse_hook(frx.window, mouse, &frx);
	mlx_hook(frx.window, 17, 0, fr_kill, &frx);
	fr_options_2();
	mlx_loop(frx.mlx);
}
