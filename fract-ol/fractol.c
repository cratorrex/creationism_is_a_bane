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

int	display_img(t_fract_ol p)
{
	mlx_put_image_to_window(p.mlx, p.window, 0, 0, 0);
	return (0);
}

//esc = 65307
//17 is kill window
int	keylog(int key, t_fract_ol p) //shorten to one var void *p
{
	ft_printf("Key in Win1 : %d\n", key);
	if (key==0xFF1B)
		fr_kill(p);//segf needs loarge struct cus fges
	//exit(0);
	return (0);
}

// colmaps
// (63<<iter)/5
// 127+pow(255*iter+36*iter+1,1.5)*128

void	iterate(float x, float y, t_fract_ol frx)
{
	int			iter;
	t_coords	coords;

	iter = 0;
	coords.z = 0;
	coords.c = 0;
	while (iter < 32)
	{
		coords.z_r = pow(coords.z, 2) - pow(coords.c, 2) + x/(100*8);
		coords.c_r = (2 * coords.z * coords.c) + y/(100*8);
		if (pow(coords.z_r, 2) + pow(coords.c_r, 2) > 4)
		{
			mlx_pixel_put(frx.mlx, frx.window, x+750, y+500, 
				127+pow(255*iter+36*iter+1,1.5)*128);
			break ;
		}
		mlx_pixel_put(frx.mlx, frx.window, x, y, 0);
		coords.z = coords.z_r;
		coords.c = coords.c_r;
		iter++;
	}

	return ;
}


int	main()
{
	t_fract_ol	frx;

	fr_init(&frx);
	// frx.image = mlx_new_image(frx.mlx, 500, 500);
	// frx.img_data = mlx_get_data_addr(frx.image,&frx.bpp, &frx.sl, &frx.endian);
	// mlx_put_image_to_window(frx.mlx,frx.window,frx.image,0,0);
	float x = 250;
	float y;
	while (x > -750)
	{
		y = 500;
		while (y > -500)
			{ iterate(x, y, frx); y--;}
			x--;
	}
	// mlx_clear_window(frx.mlx, frx.window);
	
	mlx_key_hook(frx.window, keylog, 0);
	mlx_loop_hook(frx.mlx, NULL, 0);
	mlx_hook(frx.window,17,0,fr_kill,0);
	mlx_loop(frx.mlx);
	mlx_destroy_image(frx.mlx, frx.image);
	mlx_destroy_window(frx.mlx, frx.window);
	mlx_destroy_display(frx.mlx);
	free(frx.mlx);
}
