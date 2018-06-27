/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 16:37:34 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/27 23:05:37 by mmoya       ###    #+. /#+    ###.fr     */
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

void	draw_line(t_lin *line, t_img *img) {
 
	int	e2;
	int	dx = fabs((double)(line->x1 - line->x0));
	int	dy = fabs((double)(line->y1 - line->y0));
	int	sy = line->y0 < line->y1 ? 1 : -1; 
	int	err = (dx>dy ? dx : -dy)/2;
	dprintf(1, "%i\n", err);
	while (42)
	{
		image_set_pixel(img, line->x0, line->y0, 0x00FFFFFF);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break;
		e2 = err;
		if (e2 >- dx)
		{
			err -= dy;
			line->x0 += 1;
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

int		draw_fdf(t_img *img, t_map *map, double off)
{
	double	x;
	int		y;
	t_lin	*line;

	x = 0;
	y = 0;
	!(line = malloc(sizeof(t_lin))) ? exit(-1) : 0;
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			line->x0 = (y + x/2) * 20;
			line->y0 = (x - map->map[(int)x][y] * off) * 20;
			line->x1 = (y + 1 + x/2) * 20;
			line->y1 = (x - map->map[(int)x][y + 1] * off) * 20;
			if (y < map->w - 1)
				draw_line(line, img);
			line->x0 = (y + x/2) * 20;
			line->y0 = (x - map->map[(int)x][y] * off) * 20;
			line->x1 = (y + .5 + x/2) * 20;
			line->y1 = (x + 1 - map->map[(int)x + 1][y] * off) * 20;
			if (x < map->h - 1)
				draw_line(line, img);
			y++;
		}
		x++;
	}
	free(line);
	return (0);
}
