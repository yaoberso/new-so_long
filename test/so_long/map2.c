/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:53:48 by yaoberso          #+#    #+#             */
/*   Updated: 2024/12/02 13:08:25 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_tile_images(void *mlx, t_tiles *tiles, int *width, int *height)
{
	tiles->cag = mlx_png_file_to_image(mlx, "./tiles/coinAG.png", width, height);
	tiles->cbd = mlx_png_file_to_image(mlx, "./tiles/coinBD.png", width, height);
	tiles->cbg = mlx_png_file_to_image(mlx, "./tiles/coinBG.png", width, height);
	tiles->cad = mlx_png_file_to_image(mlx, "./tiles/coinAD.png", width, height);
	tiles->db = mlx_png_file_to_image(mlx, "./tiles/droiteB.png", width, height);
	tiles->dh = mlx_png_file_to_image(mlx, "./tiles/droiteH.png", width, height);
	tiles->dd = mlx_png_file_to_image(mlx, "./tiles/droiteD.png", width, height);
	tiles->dg = mlx_png_file_to_image(mlx, "./tiles/droiteG.png", width, height);
	tiles->plein = mlx_png_file_to_image(mlx, "./tiles/plein.png", width, height);
	tiles->water = mlx_png_file_to_image(mlx, "./tiles/Water.png", width, height);
	tiles->cailloux = mlx_png_file_to_image(mlx, "./tiles/cailloux.png", width, height);
	tiles->exit = mlx_png_file_to_image(mlx, "./tiles/exit.png", width, height);
}