# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 10:21:02 by marvin            #+#    #+#              #
#    Updated: 2024/10/06 10:21:02 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = monjeu  # Change .a en fichier exécutable

CFLAGS  = -Wall -Wextra -Werror -g
CC      = gcc -Iminilibx -Ignl -Iprintf
MLX     = minilibx/libmlx.a -lz -framework OpenGL -framework AppKit -fsanitize=address
OBJS    = $(SRCS:.c=.o)

# FICHIERS SOURCES
SRCS    = verif_map2.c map2.c check_chemin2.c check_chemin.c free.c verif_map.c player.c map.c main.c gnl/get_next_line.c gnl/get_next_line_utils.c utils.c collect.c printf/ft_printf.c printf/ft_putnbr.c printf/ft_putchar.c printf/ft_puthex_lower.c printf/ft_puthex_upper.c printf/ft_putpointer.c printf/ft_putstr.c printf/ft_putunsint.c

# Règle de compilation principale
all: $(NAME)

# Génère l'exécutable en liant les fichiers objets
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)  # Lien pour générer un exécutable

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Reconstruction complète
re: fclean all

.PHONY: all clean fclean re