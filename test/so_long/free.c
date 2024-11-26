/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:39:11 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/26 13:46:13 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_main(t_game *game)
{
	free_map(game->map);
	free_tiles(game->mlx, game->tiles);
	free(game->player);
	free(game);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_tiles(void *mlx, t_tiles *tiles)
{
	if (tiles == NULL)
		return ;
	mlx_destroy_image(mlx, tiles->cag);
	mlx_destroy_image(mlx, tiles->cbd);
	mlx_destroy_image(mlx, tiles->cbg);
	mlx_destroy_image(mlx, tiles->cad);
	mlx_destroy_image(mlx, tiles->db);
	mlx_destroy_image(mlx, tiles->dh);
	mlx_destroy_image(mlx, tiles->dd);
	mlx_destroy_image(mlx, tiles->dg);
	mlx_destroy_image(mlx, tiles->plein);
	mlx_destroy_image(mlx, tiles->water);
	free(tiles);
}