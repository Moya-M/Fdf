/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 18:32:22 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/07/10 15:47:37 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_page(t_glo *glo)
{
	free(glo);
	exit(1);
}

void	draw_hint(t_glo *glo)
{
	mlx_string_put(glo->mlx->mlx, glo->mlx->win, 50, 25, 0x00FFFFFF, HINT1);
	mlx_string_put(glo->mlx->mlx, glo->mlx->win, 50, 50, 0x00FFFFFF, HINT2);
	mlx_string_put(glo->mlx->mlx, glo->mlx->win, 50, 75, 0x00FFFFFF, HINT3);
	mlx_string_put(glo->mlx->mlx, glo->mlx->win, 50, 100, 0x00FFFFFF, HINT4);
}

int		key_hook(int key, t_glo *glo)
{
	if (key == 116 || key == 121)
		glo->z += (key == 116) ? 1 : -1;
	if (key == 53)
		close_page(0);
	if (key == 67)
		glo->col = (glo->col == 0) ? 1 : 0;
	if (key == 123 || key == 124)
		glo->ox -= (key == 123) ? 5 : -5;
	if (key == 125 || key == 126)
		glo->oy += (key == 125) ? 5 : -5;
	if (key == 69 || key == 78)
		glo->off += (key == 69) ? 0.05 : -0.05;
	if (key == 69 || key == 78 || key == 123 || key == 124 ||
	key == 125 || key == 126 || key == 116 || key == 121 || key == 67)
	{
		ft_bzero((glo->img)->data, glo->img->h * glo->img->w * 4);
		draw_fdf(glo);
		mlx_clear_window(glo->mlx->mlx, glo->mlx->win);
		mlx_put_image_to_window(glo->mlx->mlx, glo->mlx->win,
		glo->img->img, 0, 0);
		draw_hint(glo);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_glo *glo;

	if (ac != 2)
		exit(-1);
	glo = malloc(sizeof(t_glo));
	glo->off = .20;
	glo->col = 0;
	glo->z = 1;
	glo->ox = 100;
	glo->oy = 250;
	glo->mlx = init_win(1000, 1000);
	glo->img = init_img(glo->mlx);
	ft_bzero(glo->img->data, glo->img->h * glo->img->w * 4);
	glo->map = map_parse(av[1]);
	draw_fdf(glo);
	mlx_put_image_to_window(glo->mlx->mlx, glo->mlx->win, glo->img->img, 0, 0);
	draw_hint(glo);
	mlx_hook(glo->mlx->win, 17, (1L << 17), close_page, glo);
	mlx_hook(glo->mlx->win, 2, 0, key_hook, glo);
	mlx_loop(glo->mlx->mlx);
	return (0);
}
