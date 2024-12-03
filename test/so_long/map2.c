/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:53:48 by yaoberso          #+#    #+#             */
/*   Updated: 2024/12/03 12:00:28 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_tile_images(void *mlx, t_tiles *tiles, int *width, int *height)
{
	tiles->cag = mlx_png_file_to_image(mlx, "./tiles/coinAG.png", width,
			height);
	tiles->cbd = mlx_png_file_to_image(mlx, "./tiles/coinBD.png", width,
			height);
	tiles->cbg = mlx_png_file_to_image(mlx, "./tiles/coinBG.png", width,
			height);
	tiles->cad = mlx_png_file_to_image(mlx, "./tiles/coinAD.png", width,
			height);
	tiles->db = mlx_png_file_to_image(mlx, "./tiles/droiteB.png", width,
			height);
	tiles->dh = mlx_png_file_to_image(mlx, "./tiles/droiteH.png", width,
			height);
	tiles->dd = mlx_png_file_to_image(mlx, "./tiles/droiteD.png", width,
			height);
	tiles->dg = mlx_png_file_to_image(mlx, "./tiles/droiteG.png", width,
			height);
	tiles->plein = mlx_png_file_to_image(mlx, "./tiles/plein.png", width,
			height);
	tiles->water = mlx_png_file_to_image(mlx, "./tiles/Water.png", width,
			height);
	tiles->cailloux = mlx_png_file_to_image(mlx, "./tiles/cailloux.png", width,
			height);
	tiles->exit = mlx_png_file_to_image(mlx, "./tiles/exit.png", width, height);
}

void	*get_tile(char tile_char, t_tiles *tiles)
{
	if (tile_char == '1')
		return (tiles->cag);
	else if (tile_char == '2')
		return (tiles->cad);
	else if (tile_char == '3')
		return (tiles->cbg);
	else if (tile_char == '4')
		return (tiles->cbd);
	else if (tile_char == 'H')
		return (tiles->dh);
	else if (tile_char == 'G')
		return (tiles->dg);
	else if (tile_char == 'D')
		return (tiles->dd);
	else if (tile_char == 'B')
		return (tiles->db);
	else if (tile_char == '0' || tile_char == 'P' || tile_char == 'A')
		return (tiles->plein);
	else if (tile_char == 'M')
		return (tiles->water);
	else if (tile_char == 'C')
		return (tiles->cailloux);
	else if (tile_char == 'E')
		return (tiles->exit);
	return (NULL);
}

int	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		map_size;

	line = NULL;
	map_size = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd) != NULL)
	{
		map_size++;
		free(line);
	}
	close(fd);
	return (map_size);
}

int	load_map_lines(const char *filename, char **map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
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
			return (0);
		}
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (1);
}
