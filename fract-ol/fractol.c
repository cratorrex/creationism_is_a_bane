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

int	mouse(int key, int x, int y, t_fract_ol *p)
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
// , . = 44 46 (iter)
//
//
//17 is kill window
//shorten to one var void *p
//segf needs loarge struct cus fges
static void	keyboard_movement(int key, t_fract_ol *p)
{
	if (key == 119)
		p->off_y -= 20;
	if (key == 115)
		p->off_y += 20;
	if (key == 97)
		p->off_x -= 20;
	if (key == 100)
		p->off_x += 20;
	if (key == 44)
		p->set_iter -= 1;
	if (key == 46)
		p->set_iter += 1;
	if (key == 65362)
		p->jul_y += 0.01;
	if (key == 65364)
		p->jul_y -= 0.01;
	if (key == 65361)
		p->jul_x -= 0.01;
	if (key == 65363)
		p->jul_x += 0.01;
}

int	keyboard(int key, t_fract_ol *p)
{
	ft_printf("Key in Win1 : %d\n", key);
	if (key == 0xFF1B || key == 113)
		fr_kill(p);
	if (key == 61)
	{
		p->off_x *= 1.25;
		p->off_y *= 1.25;
		p->zoom = p->zoom * 1.25;
	}
	if (key == 45)
	{
		p->off_x *= 0.8;
		p->off_y *= 0.8;
		p->zoom = p->zoom * 0.8;
	}
	if (key == 111)
	{
		p->off_x = 0;
		p->off_y = 0;
	}
	if (key == 99)
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

	if (count < 2)
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
	mlx_loop(frx.mlx);
}
