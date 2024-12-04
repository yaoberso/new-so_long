/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:10:43 by yaoberso          #+#    #+#             */
/*   Updated: 2024/12/03 13:08:17 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate_map(char **map)
{
	char	**new_map;
	int		i;
	int		rows;

	i = 0;
	rows = 0;
	while (map[rows] != NULL)
		rows++;
	new_map = malloc((rows + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	while (i < rows)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	find_player(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y] != NULL)
	{
		*x = 0;
		while (map[*y][*x] != '\0')
		{
			if (map[*y][*x] == 'P')
				return ;
			*x += 1;
		}
		*y += 1;
	}
}

int	explore_paths(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0')
		return (0);
	if (map[y][x] == 'M' || map[y][x] == 'V' || map[y][x] == 'C')
		return (0);
	if (map[y][x] == 'A' || map[y][x] == 'E')
	{
		map[y][x] = '0';
		return (1);
	}
	map[y][x] = 'V';
	if (explore_paths(map, x + 1, y))
		return (1);
	if (explore_paths(map, x - 1, y))
		return (1);
	if (explore_paths(map, x, y + 1))
		return (1);
	if (explore_paths(map, x, y - 1))
		return (1);
	return (0);
}

void	clear_marks(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'V')
				map[y][x] = '0';
			x++;
		}
		y++;
	}
}

int	check_paths(char **map)
{
	char	**map_copy;
	int		x;
	int		y;

	map_copy = duplicate_map(map);
	if (!map_copy)
		return (0);
	find_player(map_copy, &x, &y);
	while (1)
	{
		if (!explore_paths(map_copy, x, y))
			break ;
		clear_marks(map_copy);
		if (!remaining_targets(map_copy))
			break ;
	}
	if (remaining_targets(map_copy))
	{
		free_map(map_copy);
		ft_printf("Error\nmap avec aucun chemin valide\n");
		return (0);
	}
	free_map(map_copy);
	return (1);
}
