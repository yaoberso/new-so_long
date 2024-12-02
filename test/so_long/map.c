/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:54 by yaoberso          #+#    #+#             */
/*   Updated: 2024/12/02 13:34:58 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**load_map(const char *filename)
{
	char	**map;
	int		fd;
	char	*line;
	int		i;
	int		map_size;

	i = 0;
	map_size = 0;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		return (NULL);
	}
	while (get_next_line(fd) != NULL)
	{
		map_size++;
		free(line);
	}
	close(fd);
	map = malloc(sizeof(char *) * (map_size + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		free(line);
		if (!map[i])
		{
			free_map(map);
			close(fd);
			return (NULL);
		}
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

t_tiles	*load_tiles(void *mlx)
{
	t_tiles	*tiles;
	int		width;
	int		height;

	tiles = malloc(sizeof(t_tiles));
	if (tiles == NULL)
	{
		return (NULL);
	}
	load_tile_images(mlx, tiles, &width, &height);
	return (tiles);
}

void	place_tiles(void *mlx, void *window, t_tiles *tiles, char **map)
{
	void	*tile;
	int		y;
	int		x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tile = NULL;
			if (map[y][x] == '1')
				tile = tiles->cag;
			else if (map[y][x] == '2')
				tile = tiles->cad;
			else if (map[y][x] == '3')
				tile = tiles->cbg;
			else if (map[y][x] == '4')
				tile = tiles->cbd;
			else if (map[y][x] == 'H')
				tile = tiles->dh;
			else if (map[y][x] == 'G')
				tile = tiles->dg;
			else if (map[y][x] == 'D')
				tile = tiles->dd;
			else if (map[y][x] == 'B')
				tile = tiles->db;
			else if (map[y][x] == '0' || map[y][x] == 'P' || map[y][x] == 'A')
				tile = tiles->plein;
			else if (map[y][x] == 'M')
				tile = tiles->water;
			else if (map[y][x] == 'C')
				tile = tiles->cailloux;
			else if (map[y][x] == 'E')
				tile = tiles->exit;
			if (tile != NULL)
			{
				mlx_put_image_to_window(mlx, window, tile, x * TILE_SIZE, y
					* TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
