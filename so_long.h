/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertran <abertran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:12:39 by abertran          #+#    #+#             */
/*   Updated: 2023/04/26 18:52:46 by abertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>
# include "gnl/get_next_line.h"

typedef struct t_start
{
	int		fd;
	int		mapheight;
	int		mapwidth;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;
	int		exit_count;
	int		collectables_count;
	int		player_x;
	int		player_y;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlx;
	void	*window;

}	t_start;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

// ----------- FUNCTIONS ---------- 

int		read_map(t_start *game, char **av);
int		exit_game(t_start *game);
void	check_errors(t_start *game);
void	put_images(t_start *game);
void	put_graphics(t_start *game);
int		controls(int command, t_start *game);
void	valid_map(char *map, char *ext);
void	check_rectangle(t_start *game);
int		get_width(char *str);
void	player_position(char **map, t_start *game);
void	copy_map(char **map, t_start *game);
void	*valid_xpm(t_start *game, char *str);

#endif