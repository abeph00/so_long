/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:33:54 by abertran          #+#    #+#             */
/*   Updated: 2023/04/26 18:56:39 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	do_move(t_start *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		printf("Hurray! Now you have all your teeths back!\n");
		exit_game(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int	up_down(t_start *game, int move, int i, int j)
{
	int	k;

	if (move == 13 || move == 126)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = do_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (move == 1 || move == 125)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = do_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	printf("Steps: %i\n", game->counter);
	printf("Collectables:  %i\n", game->collectables);
	return (1);
}

static int	right_left(t_start *game, int move, int i, int j)
{
	int	k;

	if (move == 0 || move == 123)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = do_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (move == 2 || move == 124)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = do_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	printf("Steps: %i\n", game->counter);
	printf("Collectables:  %i\n", game->collectables);
	return (1);
}

int	controls(int command, t_start *game)
{
	int	works;
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (command == 53)
		exit_game(game);
	if (command == 13 || command == 126)
		works = up_down(game, command, i, j);
	if (command == 1 || command == 125)
		works = up_down(game, command, i, j);
	if (command == 0 || command == 123)
		works = right_left(game, command, i, j);
	if (command == 2 || command == 124)
		works = right_left(game, command, i, j);
	if (works)
		put_graphics(game);
	return (1);
}
