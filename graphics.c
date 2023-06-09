/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:59:55 by abertran          #+#    #+#             */
/*   Updated: 2023/04/17 22:59:55 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_start *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->window, game->player, width * 45, height * 45);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_start *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->window, game->collectable, width * 45, height * 45);
	game->collectables++;
}

void	put_images(t_start *game)
{
	game->floor = valid_xpm(game, "textures/grass.xpm");
	game->barrier = valid_xpm(game, "textures/tree.xpm");
	game->player = valid_xpm(game, "textures/oldman.xpm");
	game->exit = valid_xpm(game, "textures/exit.xpm");
	game->collectable = valid_xpm(game, "textures/tooth.xpm");
}

void	put_graphics1(t_start *game, int height)
{
	int	width;

	while (height < game->mapheight)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->barrier, width * 45, height * 45);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx,
					game->window, game->exit, width * 45, height * 45);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx,
					game->window, game->floor, width * 45, height * 45);
			width++;
		}
		height++;
	}
}

void	put_graphics(t_start *game)
{
	int	height;

	game->collectables = 0;
	height = 0;
	put_graphics1(game, height);
}
