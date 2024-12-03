/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:54 by yaoberso          #+#    #+#             */
/*   Updated: 2024/12/03 11:57:12 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**load_map(const char *filename)
{
	char	**map;
	int		map_size;

	map_size = count_lines(filename);
	if (map_size == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (map_size + 1));
	if (!map)
		return (NULL);
	if (!load_map_lines(filename, map))
	{
		free(map);
		return (NULL);
	}
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
			tile = get_tile(map[y][x], tiles);
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
