/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 18:32:22 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 23:03:09 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_page(t_glo *glo)
{
	(void)glo;
	exit(1);
}

int		key_hook(int key, t_glo *glo)
{
	if (key == 53)
		exit(0);
	// ZOOM 69; DEZOOM 78
	if (key == 69 || key == 78)
	{
		ft_bzero((glo->img)->data, glo->img->h * glo->img->w * 4);
		//mlx_clear_window(mlx->mlx, mlx->win);
		glo->off += (key == 69) ? 0.05 : -0.05;
		dprintf(1, "%f\n", glo->off);
		draw_fdf(glo->img, glo->map, glo->off);
		mlx_clear_window(glo->mlx->mlx, glo->mlx->win);
		mlx_put_image_to_window(glo->mlx->mlx, glo->mlx->win, glo->img->img, 0, 0);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_glo *glo;

	if (ac != 2)
		exit(-1);
	glo = malloc(sizeof(t_glo));
	glo->off = 1;
	glo->mlx = init_win(1000, 1000);
	glo->img = init_img(glo->mlx);
	ft_bzero(glo->img->data, glo->img->h * glo->img->w * 4);
	glo->map = map_parse(av[1]);
	draw_fdf(glo->img, glo->map, glo->off);
	mlx_put_image_to_window(glo->mlx->mlx, glo->mlx->win, glo->img->img, 0, 0);
	mlx_hook(glo->mlx->win, 17, (1L << 17), close_page, glo);
	mlx_hook(glo->mlx->win, 2, 0, key_hook, glo);
	mlx_loop(glo->mlx->mlx);
	return (0);
}
