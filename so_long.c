/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:57:27 by abertran          #+#    #+#             */
/*   Updated: 2023/05/22 18:18:31 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_start *game)
{
	game->fd = 0;
	game->mapheight = 0;
	game->mapwidth = 0;
	game->playercount = 0;
	game->columncount = 0;
	game->exitcount = 0;
	game->x_axis = 0;
	game->y_axis = 0;
	game->counter = 0;
	game->collectables = 0;
	game->collectables_count = 0;
	game->player_x = 1;
	game->player_y = 1;
	game->exit_count = 0;
	game->map = NULL;
	game->floor = 0;
	game->barrier = 0;
	game->player = 0;
	game->exit = 0;
	game->collectable = 0;
	game->mlx = 0;
	game->window = 0;
}

int	exit_game(t_start *game)
{
	int	line;

	line = 0;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	while (line < game->mapheight)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int ac, char **av)
{
	t_start	*game;

	if (ac != 2)
	{
		printf("Error: the number of arguments is not correct\n");
		exit (1);
	}
	valid_map(av[1], ".ber");
	game = (t_start *)malloc(sizeof(t_start));
	if (game == NULL)
		return (0);
	init_struct(game);
	read_map(game, av);
	check_errors(game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (game->mapwidth * 45),
			(game->mapheight * 45), "so_long");
	put_images(game);
	put_graphics(game);
	mlx_key_hook(game->window, controls, game);
	mlx_hook(game->window, 17, 0, (void *)exit, 0);
	mlx_loop(game->mlx);
}
