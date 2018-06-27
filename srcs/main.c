/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 18:32:22 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 04:53:44 by mmoya       ###    #+. /#+    ###.fr     */
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

int		key_hook(int key, void *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(0);

	return (0);
}	

void line(int x0, int y0, int x1, int y1, t_img *img) {
 
 int i = 25;
  x0 = x0 * i + 200;
  y0 = y0 * i + 200;
  x1 = x1 * i + 200;
  y1 = y1 * i + 200;
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    image_set_pixel(img, x0, y0, 0x00FFFFFF);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

int		main(int ac, char **av)
{
	t_img *img;
	t_mlx *mlx;

	(void)ac;
	mlx = init_win(1000, 1000);
	img = init_img(mlx);
	int x = 0;
	int y = 0;
	ft_bzero(img->data, img->h * img->w * 4);
	t_map *map = map_parse(av[1]);
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			if (y < map->w - 1)
				line(y + x, x - map->map[x][y] / 2, y + 1 + x, x - map->map[x][y + 1] / 2, img);
			if (x < map->h - 1)
				line(y + x, x - map->map[x][y] / 2, y + 1 + x, x + 1 - map->map[x+1][y] / 2, img);
			y++;
		}
		x++;
	}

	//mlx_key_hook(mlx->win, key_hook, NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	//mlx_clear_window(mlx->mlx, mlx->win);
	mlx_key_hook(mlx->win, key_hook, (void*)0);
	mlx_loop(mlx->mlx);
	return (0);
}
