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
	mlx_destroy_window(p.mlx, p.window);//segf needs loarge struct cus fges
	return (0);
}

void	fr_exit()
{

}
