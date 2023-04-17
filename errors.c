/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:53:15 by abertran          #+#    #+#             */
/*   Updated: 2023/04/17 13:59:54 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontalwall(t_start *game)
{
	int	width;
	
	width = 0;
	while (width < game->mapwidth)
	{
		if (!(game->map[0][width] == '1' &&
		 game->map[game->mapheight - 1][width] == '1'))
			return (0);
		width++;
	}
	return (1);
}

static int	verticalwall(t_start *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->mapwidth;
	while (height < game->mapheight)
	{
		if (!(game->map[height][0] == '1' &&
		 game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	valid_amount(t_start *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
		{
			printf("Error here: %c", game->map[height][width]);
			exit_game(game);
		}
		if (game->map[height][width] == 'C')
			game->columncount++;
		if (game->map[height][width] == 'P')
			game->playercount++;
		if (game->map[height][width] == 'E')
			game->exitcount++;
}

static void	valid_char(t_start *game)
{
	int	height;
	int	width;
	
	height = 0;
	while (height < game->mapheight - 1)
	{
		width = 0;
		while (width <= game->mapwidth)
		{
			valid_amount(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 &&
	 game->columncount > 1 && game->exitcount == 1))
	{
		printf("Error: Player, exit or collectable issue\n");
		exit_game(game);
	}
}

void check_errors(t_start *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("Error: some walls are missing in the map\n");
		exit_game(game);
	}
	valid_char(game);
}