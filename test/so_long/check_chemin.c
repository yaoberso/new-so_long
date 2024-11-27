#include "so_long.h"

int check_chemin(char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;

	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				break;
			x++;
		}
		y++;
	}
	if (map[y][x - 1] != 'M' || map[y][x - 1] != 'C' || map[y][x - 1] != 'V')
	{
		x -= 1;
		map[y][x] = 'V';
	}
	if (map[y][x + 1] != 'M' || map[y][x + 1] != 'C')
	{
		x += 1;
		map[y][x] = 'V';
	}
	if (map[y + 1][x] != 'M' || map[y + 1][x] != 'C')
	{
		y += 1;
		map[y][x] = 'V';
	}
	if (map[y - 1][x] != 'M' || map[y - 1][x - 1] != 'C')
	{
		y -= 1;
		map[y][x] = 'V';
	}
	else if (map[y][x] == 'E')
		return (1);
	else
		return (0);
}