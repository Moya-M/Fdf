/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/25 16:23:01 by mmoya        #+#   ##    ##    #+#       */
/*   Updated: 2018/06/26 18:03:45 by mmoya       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*map_size(t_map *map)
{
	int		i;

	i = 0;/*
	while (map->str[i])
	{
		while (map->h == 0 && map->str[i])
		{
			dprintf(1, "%c\n", map->str[i]);
			while (map->str[i] == ' ')
				i++;
			if (map->str[i] >= '0' && map->str[i] <= '9')
				map->w++;
			while (map->str[i] >= '0' && map->str[i] <= '9')
				i++;
			i++;
		}
		map->h++;
	}
	dprintf(1, "h %i w %i", map->h, map->w);*/
	
	while (map->str[i])
	{/*
		while (map->str[i] == ' ')
			i++;
		if ((map->str[i] >= '0' && map->str[i] <= '9') || map->str[i] == '-' || map->str[i] == '+')
			map->w++;
		while ((map->str[i] >= '0' && map->str[i] <= '9') || map->str[i] == '-' || map->str[i] == '+')
			i++;
		if (map->str[i] == '\n')
			map->h++;*/
		i++;
	}
	//map->w /= map->h;
	map->w = 21;
	dprintf(1, "h %i w %i", map->h, map->w);
	return (map);
}

t_map	*map_alloc(t_map *map)
{
	int i;

	i = 0;
	map->map = malloc(sizeof(int*) * map->h + 1);
	while (i < map->h)
	{
		map->map[i] = malloc(sizeof(int) * map->w);
		i++;
	}
	return (map);
}

t_map	*map_init(char *str)
{
	t_map	*map;
	char	*tmp;
	char	*line;
	int		fd;

	(!(map = malloc(sizeof(t_map)))) ? exit(-1) : 0;
	map->h = 0;
	map->w = 0;
	map->str = ft_strdup("");
	if (!(fd = open(str, O_RDONLY)))
		exit(-1);
	while (get_next_line(fd, &line))
	{
		tmp = map->str;
		map->str = ft_strjoin(map->str, line);
		if (ft_strlen(line) > 1)
			map->h++;
		ft_strdel(&tmp);
	}
	map = map_size(map);
	map = map_alloc(map);
	return (map);
}

t_map	*map_parse(char *map)
{
	t_map	*out;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	out = map_init(map);
	while (x < out->h)
	{
		y = 0;
		while (y < out->w)
		{
			while (ft_isspace(out->str[i]))
				i++;
			out->map[x][y] = ft_atoi(out->str + i);
			i++;
			while (ft_isdigit(out->str[i]))
				i++;
			y++;
		}
		x++;
	}
	return (out);
}
/*
int main()
{
	int y = 0;
	int x = 0;
	map_size(" 5 2 3 \n5  2   3\n5 2 3\n5 2   3\n5  2 3\n5 2 3\n5 2    3\n", &x, &y);
	while ()
	{

	}
	dprintf(1, "x%i y%i\n", x, y);
	return 0;
}*/