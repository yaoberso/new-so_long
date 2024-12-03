/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:48:49 by yaoberso          #+#    #+#             */
/*   Updated: 2024/12/03 10:32:35 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rectangular(char **map)
{
	int	i;
	int	length;
	int	current_length;

	i = 0;
	if (!map || !map[0])
		return (0);
	length = 0;
	while (map[0][length] != '\0')
		length++;
	while (map[i] != NULL)
	{
		current_length = 0;
		while (map[i][current_length] != '\0')
			current_length++;
		if (current_length != length)
		{
			ft_printf("map non rectangulaire\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	trim_newline(char **map)
{
	int	i;
	int	length;

	i = 0;
	while (map[i] != NULL)
	{
		length = 0;
		while (map[i][length] != '\0')
			length++;
		if (length > 0 && map[i][length - 1] == '\n')
			map[i][length - 1] = '\0';
		i++;
	}
}

int	verif_map(char **map, char c)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	ft_printf("caractere %c manquant\n", c);
	return (0);
}

int	check_wall(char **map)
{
	int	len_x;
	int	len_y;

	len_x = ft_strlen(map[0]);
	len_y = 0;
	while (map[len_y] != NULL)
		len_y++;
	if (!check_borders(map, len_x, len_y))
	{
		ft_printf("map non entouree de murs\n");
		return (0);
	}
	return (1);
}

int	check_other_carac(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != '2'
				&& map[y][x] != '3' && map[y][x] != '4' && map[y][x] != 'P'
				&& map[y][x] != 'A' && map[y][x] != 'H' && map[y][x] != 'G'
				&& map[y][x] != 'D' && map[y][x] != 'B' && map[y][x] != 'M'
				&& map[y][x] != 'C' && map[y][x] != 'E')
			{
				ft_printf("caractere inconnu\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
