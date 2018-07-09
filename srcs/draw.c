/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 16:37:34 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/07/09 18:17:57 by mmoya       ###    #+. /#+    ###.fr     */
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

void	draw_line(t_lin *line, t_img *img, double i, int col)
{
	line->dx = fabs((double)(line->x1 - line->x0));
	line->dy = fabs((double)(line->y1 - line->y0));
	line->sy = line->y0 < line->y1 ? 1 : -1;
	line->err = (line->dx > line->dy ? line->dx : -line->dy) / 2;
	while (42)
	{
		if (col)
			image_set_pixel(img, line->x0, line->y0, 0x00FFFF00 -
		(((int)fabs(i) * 20) % 255) * 255);
		else
			image_set_pixel(img, line->x0, line->y0, 0x00FFFFFF);
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break ;
		line->e2 = line->err;
		if (line->e2 > -line->dx)
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

void	draw_lines(t_glo *glo, t_lin *line, t_cor *cord)
{
	line->x0 = (cord->y + cord->x / 2) * cord->z + glo->ox;
	line->y0 = (cord->x - MAPXY * glo->off) * cord->z + glo->oy;
	line->x1 = (cord->y + 1 + cord->x / 2) * cord->z + glo->ox;
	line->y1 = (cord->x - MAPXY1 * glo->off) * cord->z + glo->oy;
	if (cord->y < glo->map->w - 1)
		draw_line(line, glo->img, MAPXY, glo->col);
	line->x0 = (cord->y + cord->x / 2) * cord->z + glo->ox;
	line->y0 = (cord->x - MAPXY * glo->off) * cord->z + glo->oy;
	line->x1 = (cord->y + .5 + cord->x / 2) * cord->z + glo->ox;
	line->y1 = (cord->x + 1 - MAPX1Y * glo->off) * cord->z + glo->oy;
	if (cord->x < glo->map->h - 1)
		draw_line(line, glo->img, MAPXY, glo->col);
}

int		draw_fdf(t_glo *glo)
{
	t_cor	*cord;
	t_lin	*line;

	!(cord = malloc(sizeof(t_cor))) ? exit(-1) : 0;
	!(line = malloc(sizeof(t_lin))) ? exit(-1) : 0;
	cord->x = 0;
	cord->z = 600 / ((glo->map->w > glo->map->h) ? glo->map->w : glo->map->h)
	* glo->z;
	while (cord->x < glo->map->h)
	{
		cord->y = 0;
		while (cord->y < glo->map->w)
		{
			draw_lines(glo, line, cord);
			cord->y++;
		}
		cord->x++;
	}
	free(cord);
	free(line);
	return (0);
}
