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
	x = y;
	ft_printf("Mouse in Win1 : %d\n", key);
	if (key == 4)
	{
		p->zoom = p->zoom * 1.25;
		fr_gen(p);
	}
	if (key == 5)
	{
		p->zoom = p->zoom * 0.8;
		fr_gen(p);
	}
	return (0);
}

//esc = 65307
// wasd = 119 97 115 100
//
//
//
//17 is kill window
//shorten to one var void *p
//segf needs loarge struct cus fges
int	keylog(int key, t_fract_ol *p)
{
	ft_printf("Key in Win1 : %d\n", key);
	if (key == 0xFF1B)
		fr_kill(p);
	if (key == 119)
	{
		p->zoom = p->zoom * 1.25;
		fr_gen(p);
	}
	if (key == 115)
	{
		p->zoom = p->zoom * 0.8;
		fr_gen(p);
	}
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
	mlx_key_hook(frx.window, keylog, &frx);
	mlx_loop_hook(frx.mlx, NULL, 0);
	mlx_mouse_hook(frx.window, mouse, &frx);
	mlx_hook(frx.window, 17, 0, fr_kill, &frx);
	mlx_loop(frx.mlx);
}
