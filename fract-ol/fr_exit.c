/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:40:13 by thtay             #+#    #+#             */
/*   Updated: 2026/03/13 16:40:15 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	fr_kill(t_fract_ol p)
{
	ft_printf("hello?");

		//mlx_destroy_image(p.mlx, p.image);

	// mlx_destroy_window(p.mlx, p.window);//segf needs loarge struct cus fges
	// mlx_destroy_display(p.mlx);
	mlx_loop_end(p.mlx);
	// p.mlx = NULL;
	exit (0);
}

int	fr_init_e(t_fract_ol *p, int step)
{
	if (step > 1)
		mlx_destroy_window(p->mlx, p->window);
	if (step > 0)
		mlx_destroy_display(p->mlx);
	exit(1);	
}

void	fr_exit()
{

}
