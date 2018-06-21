/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 15:04:48 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 15:05:13 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx	*init_win(int w, int h)
{
	t_mlx	*r;

	if ((r = malloc(sizeof(t_mlx))) == NULL)
		exit(-1);
	r->mlx = mlx_init();
	r->win = mlx_new_window(r->mlx, w, h, "TEST");
	r->w = w;
	r->h = h;
	return (r);
}

t_img	*init_img(t_mlx *mlx)
{
	t_img	*img;
	int		tmp[3];

	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(-1);
	img->img = mlx_new_image(mlx->mlx, mlx->w, mlx->h);
	img->data = (int*)mlx_get_data_addr(img->img, &tmp[0], &tmp[1], &tmp[2]);
	img->w = mlx->w;
	img->h = mlx->h;
	return (img);
}
