#include "so_long.h"

char **duplicate_map(char **map)
{
	char **new_map;
	int i;
	int rows;

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

/*int check_pos(char **map, int x, int y)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0')
        return (0);
	if (map[y][x] == 'M' || map[y][x] == 'C' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'A')
		map[y][x] = '0';
	else
		map[y][x] = 'V';
	if (check_pos(map, x, (y - 1)))
		return (1);
	if (check_pos(map, x, (y + 1)))
		return (1);
	if (check_pos(map, (x - 1), y))
		return (1);
	if (check_pos(map, (x + 1), y))
		return (1);
	return (0);
}

int check_chemin(char **map)
{
	int x;
	int y;
	char **new_map;

	new_map = duplicate_map(map);
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
		if (map[y][x] == 'P')
				break;
		y++;
	}
	check_pos(new_map, x, y);
	y = 0;
	while (new_map[y] != NULL)
	{
		x = 0;
		while (new_map[y][x] != '\0')
		{
			if (new_map[y][x] == 'A' || map[y][x] == 'E')
			{
				free_map(new_map);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_map(new_map);
	return (1);
}*/

int check_pos(char **map, int x, int y, int *collected)
{
    // Vérification des bornes de la carte
    if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0')
        return (0);

    // Si la case est un mur ou déjà visitée, on l'ignore
    if (map[y][x] == 'M' || map[y][x] == 'V')
        return (0);

    // Si on trouve un collectable, on le prend (on l'ignore mais on marque comme visité)
    if (map[y][x] == 'A')
    {
        (*collected)++;
        map[y][x] = 'V';  // Marquer comme visité
    }

    // Si on trouve la sortie, on la marque comme visitée et on retourne
    if (map[y][x] == 'E')
    {
        map[y][x] = 'V';
        return (1);  // Retourner true si on trouve la sortie
    }

    // Marquer cette case comme visitée
    map[y][x] = 'V';

    // Appeler récursivement les quatre directions : haut, bas, gauche, droite
    if (check_pos(map, x, y - 1, collected)) return (1); // haut
    if (check_pos(map, x, y + 1, collected)) return (1); // bas
    if (check_pos(map, x - 1, y, collected)) return (1); // gauche
    if (check_pos(map, x + 1, y, collected)) return (1); // droite

    return (0);
}

// Fonction principale pour vérifier si le chemin est valide et si tous les collectables sont récupérés
int check_chemin(char **map)
{
    int x, y;
    int collected = 0;  // Compteur de collectables récupérés
    char **new_map;

    new_map = duplicate_map(map);  // Dupliquer la carte pour ne pas la modifier directement
    x = 0;
    y = 0;

    // Chercher la position du joueur ('P')
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            if (map[y][x] == 'P')
                break;
            x++;
        }
        if (map[y][x] == 'P')
            break;
        y++;
    }

    // Appeler check_pos pour explorer la carte à partir du joueur
    if (!check_pos(new_map, x, y, &collected))
    {
        free_map(new_map);
        return (0);  // Si on ne trouve pas un chemin valide
    }

    // Vérifier si tous les collectables ont été récupérés
    y = 0;
    while (new_map[y] != NULL)
    {
        x = 0;
        while (new_map[y][x] != '\0')
        {
            if (new_map[y][x] == 'A')  // Si un collectable n'a pas été récupéré
            {
                free_map(new_map);
                return (0);
            }
            x++;
        }
        y++;
    }

    // Vérifier si la sortie a été atteinte
    y = 0;
    while (new_map[y] != NULL)
    {
        x = 0;
        while (new_map[y][x] != '\0')
        {
            if (new_map[y][x] == 'E')  // Si la sortie n'a pas été atteinte
            {
                free_map(new_map);
                return (0);
            }
            x++;
        }
        y++;
    }

    free_map(new_map);
    return (1);  // Chemin valide et tous les collectables ont été récupérés
}