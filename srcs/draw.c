/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 16:37:34 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 19:44:58 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook(int key, void *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(0);

	return (0);
}

void	image_set_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->w || y < 0 || y >= img->h)
		return ;
	img->data[x + y * img->w] = color;
}

void	draw_line(t_lin *line, t_img *img) {
 
	int	e2;
	int	dx = fabs((double)(line->x1 - line->x0));
	int	sx = line->x0 < line->x1 ? 1 : -1;
	int	dy = fabs((double)(line->y1 - line->y0));
	int	sy = line->y0 < line->y1 ? 1 : -1; 
	int	err = (dx>dy ? dx : -dy)/2;

	while (42)
	{
		image_set_pixel(img, line->x0, line->y0, 0x00FFFFFF);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break;
		e2 = err;
		if (e2 >- dx)
		{
			err -= dy;
			line->x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			line->y0 += sy;
		}
	}
}

/*
void draw_line(int x0, int y0, int x1, int y1, t_img *img) {
 
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
}*/

int		draw_fdf(t_mlx *mlx, t_img *img, char *str)
{
	int		x;
	int		y;
	t_map	*map;
	t_lin	*line;

	x = 0;
	y = 0;
	map = map_parse(str);
	!(line = malloc(sizeof(t_lin))) ? exit(-1) : 0;
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			line->x0 = (y + x/2) * 20;
			line->y0 = (x - map->map[x][y] / 5) * 20;
			line->x1 = (y + 1 + x/2) * 20;
			line->y1 = (x - map->map[x][y + 1] / 5) * 20;
			if (y < map->w - 1)
				draw_line(line, img);
			line->x0 = (y + x/2) * 20;
			line->y0 = (x - map->map[x][y] / 5) * 20;
			line->x1 = (y + 1 + x/2) * 20;
			line->y1 = (x + 1 - map->map[x + 1][y] / 5) * 20;
			if (x < map->h - 1)
				draw_line(line, img);
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
