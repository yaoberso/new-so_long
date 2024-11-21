/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:48:49 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/21 14:22:04 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int check_map_rectangular(char **map)
{
    int i = 0;
    int length;

    if (!map || !map[0])
        return (0);
    length = 0;
    while (map[0][length] != '\0')
        length++;
    while (map[i] != NULL)
    {
        int current_length = 0;
        while (map[i][current_length] != '\0')
            current_length++;
        if (current_length != length)
            return (0);
        i++;
    }
    return (1);
}

void trim_newline(char **map)
{
    int i = 0;

    while (map[i] != NULL)
    {
        int length = 0;
        while (map[i][length] != '\0')
            length++;
        if (length > 0 && map[i][length - 1] == '\n')
            map[i][length - 1] = '\0';
        i++;
    }
}

int	verif_map(char **map, char c)
{
	int x;
	int y;
	
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while(map[y][x] != '\0')
		{
			if (map[y][x] == c)
			{
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
