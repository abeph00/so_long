/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:29:55 by abertran          #+#    #+#             */
/*   Updated: 2023/04/26 18:52:36 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectables(char **map, t_start *game)
{
	int	x;
	int	y;
	int	c;

	y = 1;
	x = 1;
	c = 0;
	while (y < game->mapheight)
	{
		x = 1;
		while (x < game->mapwidth)
		{
			if (map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

static void	route_c(char **map, int x, int y, t_start *game)
{
	if (map[y][x] == 'C')
		game->collectables_count++;
	if (map[y - 1][x] == '0' || map[y + 1][x] == '0' ||
		map[y][x - 1] == '0' || map[y][x + 1] == '0')
		map[y][x] = '.';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		route_c(map, x, y - 1, game);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		route_c(map, x, y + 1, game);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		route_c(map, x - 1, y, game);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		route_c(map, x + 1, y, game);
	map[y][x] = '.';
}

static void	route_e(char **map, int x, int y, t_start *game)
{
	if (map[y][x] == 'E')
		game->exit_count++;
	if (map[y - 1][x] == '0' || map[y + 1][x] == '0' ||
		map[y][x - 1] == '0' || map[y][x + 1] == '0')
		map[y][x] = '.';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'E')
		route_e(map, x, y - 1, game);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'E')
		route_e(map, x, y + 1, game);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'E')
		route_e(map, x - 1, y, game);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'E')
		route_e(map, x + 1, y, game);
	map[y][x] = '.';
}

static void	check_route(char **map, t_start *game)
{
	int	c;
	int	line;

	line = 0;
	c = count_collectables(map, game);
	route_c(map, game->player_x, game->player_y, game);
	if (game->collectables_count != c)
	{
		printf("No route available to all collectables\n");
		exit_game(game);
	}
	map = (char **)malloc(sizeof(char *) * game->mapheight);
	copy_map(map, game);
	route_e(map, game->player_x, game->player_y, game);
	while (line < game->mapheight)
		free(map[line++]);
	free(map);
	if (game->exit_count != 1)
	{
		printf("No route available to exit, your player has starved\n");
		exit_game(game);
	}
}

void	player_position(char **map, t_start *game)
{
	int	line;

	line = 0;
	while (game->player_y < game->mapheight
		&& (map[game->player_y][game->player_x] != 'P'))
	{
		game->player_x = 1;
		while (game->player_x < game->mapwidth
			&& map[game->player_y][game->player_x] != 'P')
		{
			if (map[game->player_y][game->player_x] == 'P')
				break ;
			game->player_x++;
		}
		if (map[game->player_y][game->player_x] == 'P')
			break ;
		game->player_y++;
	}
	check_route(map, game);
	while (line < game->mapheight)
		free(map[line++]);
	free(map);
}
