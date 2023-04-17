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

void	put_images(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"......", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"......", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"......", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"......", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"......", &i, &j);
}