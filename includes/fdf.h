/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 18:34:04 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 18:32:06 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_img {
	void		*img;
	int			*data;
	int			w;
	int			h;
}				t_img;

typedef struct	s_lin {
	int			x0;
	int			x1;
	int			y0;
	int			y1;
}				t_lin;

typedef struct	s_map {
	char		*str;
	int			**map;
	int			w;
	int			h;
}				t_map;

typedef struct	s_mlx {
	void		*mlx;
	void		*win;
	int			w;
	int			h;
}				t_mlx;

t_mlx			*init_win(int w, int h);
t_img			*init_img(t_mlx *mlx);
t_map			*map_parse(char *map);
int				draw_fdf(t_mlx *mlx, t_img *img, char *str);

#endif