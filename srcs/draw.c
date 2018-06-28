/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 16:37:34 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/28 16:22:21 by mmoya       ###    #+. /#+    ###.fr     */
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

void	draw_line(t_lin *line, t_img *img)
{
	line->dx = fabs((double)(line->x1 - line->x0));
	line->dy = fabs((double)(line->y1 - line->y0));
	line->sy = line->y0 < line->y1 ? 1 : -1; 
	line->err = (line->dx > line->dy ? line->dx : -line->dy)/2;
	while (42)
	{
		image_set_pixel(img, line->x0, line->y0, 0x00FFFFFF);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break;
		line->e2 = line->err;
		if (line->e2 >- line->dx)
		{
			line->err -= line->dy;
			line->x0 += 1;
		}
		if (line->e2 < line->dy)
		{
			line->err += line->dx;
			line->y0 += line->sy;
		}
	}
}

int		draw_fdf(t_img *img, t_map *map, double off)
{
	double	x;
	int		y;
	int		z;
	t_lin	*line;

	x = 0;
	z = 600 / ((map->w > map->h) ? map->w : map->h);
	!(line = malloc(sizeof(t_lin))) ? exit(-1) : 0;
	while (x < map->h)
	{
		y = 0;
		while (y < map->w)
		{
			line->x0 = (y + x/2) * z;
			line->y0 = (x - map->map[(int)x][y] * off) * z;
			line->x1 = (y + 1 + x/2) * z;
			line->y1 = (x - map->map[(int)x][y + 1] * off) * z;
			if (y < map->w - 1)
				draw_line(line, img);
			line->x0 = (y + x/2) * z;
			line->y0 = (x - map->map[(int)x][y] * off) * z;
			line->x1 = (y + .5 + x/2) * z;
			line->y1 = (x + 1 - map->map[(int)x + 1][y] * off) * z;
			if (x < map->h - 1)
				draw_line(line, img);
			y++;
		}
		x++;
	}
	free(line);
	return (0);
}
