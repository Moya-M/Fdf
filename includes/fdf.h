/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 18:34:04 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 17:02:32 by mmoya       ###    #+. /#+    ###.fr     */
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

# define MAPXY glo->map->map[(int)cord->x][cord->y]
# define MAPXY1 glo->map->map[(int)cord->x][cord->y + 1]
# define MAPX1Y glo->map->map[(int)cord->x + 1][cord->y]

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
	int			e2;
	int			dx;
	int			dy;
	int			sy; 
	int			err;
}				t_lin;

typedef struct	s_map {
	char		*str;
	double		**map;
	int			w;
	int			h;
}				t_map;

typedef struct	s_mlx {
	void		*mlx;
	void		*win;
	int			w;
	int			h;
}				t_mlx;

typedef struct	s_cor {
	double		x;
	int			y;
	int			z;
}				t_cor;

typedef struct	s_glo {
	t_img		*img;
	t_mlx		*mlx;
	t_map		*map;
	double		off;
}				t_glo;

t_mlx			*init_win(int w, int h);
t_img			*init_img(t_mlx *mlx);
t_map			*map_parse(char *map);
int				draw_fdf(t_glo *glo);

#endif