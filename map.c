/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:39:58 by abertran          #+#    #+#             */
/*   Updated: 2023/05/22 17:53:55 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width(char *str)
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
		{
			break ;
		}
	}
	if (game->mapheight == 0 && game->mapwidth == 0)
	{
		printf("Error: Map is empty\n");
		exit_game(game);
	}
	close (game->fd);
	return (1);
}
