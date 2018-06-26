/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 18:32:22 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/26 16:11:27 by mmoya       ###    #+. /#+    ###.fr     */
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
	(void)av;
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
			//dprintf(1, "%i ", map->map[x][y]);
			line(y*50, x*50, y*50+20, x*50+map->map[x][y]*5, img);
			//image_set_pixel(img, y*50, (x*50) - (map->map[x][y]*5), 0x00FFFFFF);
			y++;
		}
		//dprintf(1, "\n");
		x++;
	}
	/*
	while (x++ < img->w)
	{
		while (y++ < img->h)
			image_set_pixel(img, x, y, 0x00FFFFFF);
		y = -1;
	}*/
	//mlx_key_hook(mlx->win, key_hook, NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	//mlx_clear_window(mlx->mlx, mlx->win);
	mlx_key_hook(mlx->win, key_hook, (void*)0);
	mlx_loop(mlx->mlx);
	return (0);
}
