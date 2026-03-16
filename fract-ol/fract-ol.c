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

#include "fract-ol.h"

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

int	main()
{
	t_fract_ol	frx;

	frx.mlx = mlx_init();
	if (!frx.mlx)
		return (1);
	frx.window = mlx_new_window(frx.mlx, 500, 500, "Hello World!");
	if (!frx.window)
		return (1);
	frx.image = mlx_new_image(frx.mlx,20,20);
	if (!frx.image)
		return (1);
	mlx_put_image_to_window(frx.mlx,frx.window,frx.image,20,20);
	mlx_destroy_image(frx.mlx, frx.image);

	mlx_clear_window(frx.mlx, frx.window);
	mlx_key_hook(frx.window, keylog, 0);
	mlx_hook(frx.window,17,0,fr_kill,0);
	mlx_loop(frx.mlx);
	mlx_destroy_display(frx.mlx);
	free(frx.mlx);
}
