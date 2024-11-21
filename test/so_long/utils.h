/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:18:46 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/21 14:21:07 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "map.h"
# include "player.h"

int		check_map_rectangular(char **map);
int		ft_strcol(char *str);
char	*ft_strdup(char *str);
int		cherche_py(char **map);
int		cherche_px(char **map);
int		cherche_collect(char **map);
void	trim_newline(char **map);
int		verif_map(char **map, char c);

#endif