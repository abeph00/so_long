/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:39:58 by abertran          #+#    #+#             */
/*   Updated: 2023/04/20 21:19:41 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_width(char *str)
{
	int	width;

	width = 0;
	while (str[width] != '\0')
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_start *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->mapheight++;
	temp = (char **)malloc(sizeof(char *) * (game->mapheight + 1));
	temp[game->mapheight] = NULL;
	while (i < game->mapheight - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

void	valid_map(char *map, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(map) - ft_strlen(ext);
	j = 0;
	while (map[i + j] && ext[j])
	{
		if (map[i + j] == ext[j])
			j++;
		else
		{
			printf("Error: The map has to be a .ber file\n");
			exit(1);
		}
	}
}

void	check_rectangle(t_start *game)
{
	int	i;
	int	w;	

	i = 1;
	game->mapwidth = get_width(game->map[0]);
	while (game->map[i])
	{
		w = get_width(game->map[i]);
		if (w != game->mapwidth)
		{
			printf("Error: Width not the same in all lines\n");
			exit_game(game);
		}
		game->mapwidth = get_width(game->map[i]);
		i++;
	}
}

int	read_map(t_start *game, char **av)
{
	char	*reading;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
	{
		printf("Error: Unable to open the map\n");
		exit_game(game);
	}
	while (TRUE)
	{
		reading = get_next_line(game->fd);
		if (!add_line(game, reading))
			break ;
	}
	close (game->fd);
	return (1);
}
