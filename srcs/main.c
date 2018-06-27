/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 18:32:22 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 16:53:07 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_img *img;
	t_mlx *mlx;

	if (ac != 2)
		exit(-1);
	mlx = init_win(1000, 1000);
	img = init_img(mlx);
	ft_bzero(img->data, img->h * img->w * 4);
	draw_fdf(mlx, img, av[1]);
	return (0);
}
