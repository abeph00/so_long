/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:57:27 by abertran          #+#    #+#             */
/*   Updated: 2023/04/13 16:42:46 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_start	*game;
	
	if (ac != 2)
		return (0);
	game = (t_start *)malloc(sizeof(t_start));
	if (game == NULL)
		return (0);
	read_map(&game, av);
}