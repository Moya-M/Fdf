/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 18:32:22 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/20 17:38:13 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	image_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	img->data[x + y * img->w] = color;
}

int		loop_hook()
{
	dprintf(1, "TES\n");
	return (0);
}	

int		main(int ac, char **av)
{
	t_img *img;
	t_mlx *mlx;

	(void)ac;
	(void)av;
	mlx = init_win(500, 500);
	img = init_img(mlx);
	int x = -1;
	int y = -1;
	ft_bzero(img->data, img->h * img->w * 4);
	while (x++ < img->w)
	{
		while (y++ < img->h)
			image_set_pixel(img, x, y, 0x0000FF00);
		y = -1;
	}
	mlx_key_hook(mlx->win, loop_hook, NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	//mlx_clear_window(mlx->mlx, mlx->win);
	mlx_loop(mlx->mlx);
	// mlx_loop_hook(mlx->mlx, loop_hook, NULL);
	return (0);
}
