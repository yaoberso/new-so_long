/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:52:26 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/28 12:25:06 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define TILE_SIZE 64

t_player	*init_player(int start_x, int start_y, char **map, void *window)
{
	int			width;
	int			height;
	t_player	*player;
	void		*mlx;

	mlx = mlx_init();
	player = malloc(sizeof(t_player));
	if (!player)
	{
		return (NULL);
	}
	player->x = start_x;
	player->y = start_y;
	player->mlx = mlx;
	player->window = window;
	player->map = map;
	player->image = mlx_png_file_to_image(mlx, "./tiles/player.png", &width,
			&height);
	if (!player->image)
	{
		free(player);
		return (NULL);
	}
	return (player);
}

void	check_new_coord(int keycode, int *new_x, int *new_y, t_player *player)
{
	if (keycode == 13)
	{
		(*new_y)--;
	}
	else if (keycode == 0)
	{
		(*new_x)--;
	}
	else if (keycode == 1)
	{
		(*new_y)++;
	}
	else if (keycode == 2)
	{
		(*new_x)++;
	}
	else if (keycode == 53)
	{
		free(player);
		mlx_destroy_window(player->mlx, player->window);
		exit(0);
	}
}

void	check_exit_condition(t_player *player, char **map)
{
	if (cherche_collects(map) == 0)
	{
		free(player);
		mlx_destroy_window(player->mlx, player->window);
		exit(0);
	}
}

void	move_player(int keycode, t_player *player, char **map)
{
	static int	count = 0;
	int			new_x;
	int			new_y;
	int			len_y;
	int			len_x;

	new_x = player->x;
	new_y = player->y;
	len_y = 0;
	len_x = ft_strlen(map[0]);
	check_new_coord(keycode, &new_x, &new_y, player);
	while (map[len_y] != NULL)
		len_y++;
	if (new_x >= 0 && new_x < len_x && new_y >= 0 && new_y < len_y)
	{
		if (map[new_y][new_x] == 'A')
			map[new_y][new_x] = '0';
		if ((keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
			&& map[new_y][new_x] != 'M' && map[new_y][new_x] != 'C')
		{
			count++;
			ft_printf("compteur de deplacement: %d\n", count);
			player->x = new_x;
			player->y = new_y;
		}
		if (map[new_y][new_x] == 'E')
			check_exit_condition(player, map);
	}
}

void	draw_player(void *mlx, void *window, t_player *player)
{
	mlx_put_image_to_window(mlx, window, player->image, player->x * TILE_SIZE,
		player->y * TILE_SIZE);
}
