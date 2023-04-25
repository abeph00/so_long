/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:08:25 by abertran          #+#    #+#             */
/*   Updated: 2023/04/25 15:43:30 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	map_copy(char **map, t_start *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->mapheight)
		map[i] = (char *)malloc(sizeof(char) * game->mapwidth);
	i = 0;
	while (i < game->mapheight)
	{
	j = 0;
		while (j < game->mapwidth)
		{
			map[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
}
