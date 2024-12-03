/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:46:31 by yaoberso          #+#    #+#             */
/*   Updated: 2024/12/03 10:33:13 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_pe(char **map, char c)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
	{
		ft_printf("nombre de %c incorrect");
		return (0);
	}
	else
		return (1);
}

int	check_borders(char **map, int len_x, int len_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < len_x)
	{
		if (map[0][x] != 'M' || map[len_y - 1][x] != 'M')
			return (0);
		x++;
	}
	y = 0;
	while (y < len_y)
	{
		if (map[y][0] != 'M' || map[y][len_x - 1] != 'M')
			return (0);
		y++;
	}
	return (1);
}
