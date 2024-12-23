/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:56:46 by yaoberso          #+#    #+#             */
/*   Updated: 2024/12/03 11:54:08 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define TILE_SIZE 64
# define MAX_LINES 100
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 640

typedef struct s_tiles
{
	void		*cag;
	void		*cad;
	void		*cbd;
	void		*cbg;
	void		*db;
	void		*dd;
	void		*dg;
	void		*dh;
	void		*plein;
	void		*water;
	void		*cailloux;
	void		*exit;
}				t_tiles;

typedef struct s_player
{
	int			x;
	int			y;
	void		*image;
	void		*mlx;
	void		*window;
	char		**map;
	int			new_x;
	int			new_y;
	int			len_y;
	int			len_x;
	t_tiles		*tiles;
}				t_player;

typedef struct s_collect
{
	int			x;
	int			y;
	void		*image;
	void		*mlx;
	void		*window;
	char		**map;
	t_tiles		*tiles;
}				t_collect;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_tiles		*tiles;
	t_player	*player;
	char		**map;
}				t_game;

int				load_map_lines(const char *filename, char **map);
int				count_lines(const char *filename);
void			*get_tile(char tile_char, t_tiles *tiles);
int				check_borders(char **map, int len_x, int len_y);
int				check_pe(char **map, char c);
void			load_tile_images(void *mlx, t_tiles *tiles, int *width,
					int *height);
int				remaining_targets(char **map);
int				cherche_collects(char **map);
int				check_paths(char **map);
void			free_main(t_game *game);
void			free_map(char **map);
void			free_tiles(void *mlx, t_tiles *tiles);
char			**load_map(const char *filename);
t_tiles			*load_tiles(void *mlx);
void			place_tiles(void *mlx, void *window, t_tiles *tiles,
					char **map);
t_player		*init_player(int start_x, int start_y, char **map,
					void *window);
void			move_player(int keycode, t_player *player, char **map);
void			draw_player(void *mlx, void *window, t_player *player);
void			draw_collect(void *mlx, void *window, char **map);
int				check_map_rectangular(char **map);
int				ft_strcol(char *str);
char			*ft_strdup(char *str);
int				cherche_py(char **map);
int				cherche_px(char **map);
void			cherche_collect(char **map, int *x, int *y);
void			trim_newline(char **map);
int				verif_map(char **map, char c);
int				check_wall(char **map);
int				check_other_carac(char **map);

#endif