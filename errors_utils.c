/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:08:25 by abertran          #+#    #+#             */
/*   Updated: 2023/04/26 18:57:39 by abertran         ###   ########.fr       */
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

void	copy_map(char **map, t_start *game)
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

void	*valid_xpm(t_start *game, char *str)
{
	void	*img;
	int		px;

	px = 45;
	img = mlx_xpm_file_to_image(game->mlx, str, &px, &px);
	if (!img)
	{
		printf("Error: .xpm issue\n");
		exit_game(game);
	}
	return (img);
}
