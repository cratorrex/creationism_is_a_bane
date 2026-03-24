/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:33:40 by thtay             #+#    #+#             */
/*   Updated: 2026/02/05 16:33:42 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <math.h>
# include "../minilibx/mlx.h"
//# include "../minilibx/mlx_int.h" //only if something dumb doesn't work
//change this wherever importing mlx

//bpp bits per pixel
//sl size of line
typedef struct s_fract_ol
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*img_data;
	int			endian;
	int			sl;
	int			bpp;

	int			set_fract;
	int			set_iter;
	int			resx;
	int			resy;
	int			set_pow;
	float		zoom;
	int			col;
}	t_fract_ol;

typedef struct s_coords
{
	float	z;
	float	c;
	float	z_r;
	float	c_r;
}	t_coords;

void	fr_options(void);
void	fr_init(t_fract_ol *mlx, char **vec);

int		fr_init_e(t_fract_ol *p, int step);
int		fr_kill(t_fract_ol *p);
//think
//void	fr_exit(); //think

void	fr_gen(t_fract_ol *frx);
void	fr_colmap(t_fract_ol frx, float x, float y, int i);
void	fr_colmap_null(t_fract_ol frx, float x, float y);

void	fr_mandel2(float x, float y, t_fract_ol frx);

#endif
