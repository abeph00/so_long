#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>
# include "GNL/get_next_line.h"

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

	char	**map;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_start;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

int	read_map(t_start *game, char **av);

#endif