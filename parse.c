/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:29:55 by abertran          #+#    #+#             */
/*   Updated: 2023/05/24 18:13:59 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	route_c(char **map, int x, int y, t_start *game)
{
	if (map[y][x] == 'C')
		game->collectables_count++;
	if (map[y - 1][x] == '0' || map[y + 1][x] == '0' ||
		map[y][x - 1] == '0' || map[y][x + 1] == '0' || map[y - 1][x] == 'C'
		|| map[y + 1][x] == 'C' || map[y][x - 1] == 'C' || map[y][x + 1] == 'C')
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
		map[y][x - 1] == '0' || map[y][x + 1] == '0' || map[y - 1][x] == 'C'
		|| map[y + 1][x] == 'C' || map[y][x - 1] == 'C' || map[y][x + 1] == 'C')
		map[y][x] = '.';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'E' || map[y - 1][x] == 'C')
		route_e(map, x, y - 1, game);
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'E' || map[y + 1][x] == 'C')
		route_e(map, x, y + 1, game);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'E' || map[y][x - 1] == 'C')
		route_e(map, x - 1, y, game);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'E' || map[y][x + 1] == 'C')
		route_e(map, x + 1, y, game);
	map[y][x] = '.';
}

static void	check_route(char **map, t_start *game)
{
	int	line;

	line = 0;
	route_c(map, game->player_x, game->player_y, game);
	if (game->collectables_count != game->columncount)
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
