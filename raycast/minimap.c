/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:36:36 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/26 15:04:04 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	check_map(t_game *game, int y, int x)
{
	return (1);
}

void	print_minimap2(t_game *game, int i, int **map, int x)
{
	int	j;
	int	y;

	y = game->plyr_y - 2;
	j = -1;
	while(++j < 5)
	{
		if (map[y][x] >= 1)
			mlx_put_image_to_window(game->mlx, game->wido, game->t_wall, game->map_posx, game->map_posy);
		else if (map[y][x] == -1)
			mlx_put_image_to_window(game->mlx, game->wido, game->t_south, game->map_posx, game->map_posy);
		else if (map[y][x] == 0)
			mlx_put_image_to_window(game->mlx, game->wido, game->t_floor, game->map_posx, game->map_posy);
		if (i == 2 && j == 2)
			mlx_put_image_to_window(game->mlx, game->wido, game->t_plyr, game->map_posx, game->map_posy);
		game->map_posy += 16;
		y++;
	}
}

void	print_minimap(t_game *game)
{
	int	**map;
	int i;
	int plyr_x;

	plyr_x = game->plyr_x -2;
	map = game->cubdat->map;
	i = -1;
	while(++i < 5)
	{
		print_minimap2(game, i, map, plyr_x);
		game->map_posy = 25;
		game->map_posx += 16;
		plyr_x++;
	}
	game->map_posx = 960;
}

void	import_sources(t_game *game)
{
	int size;

	game->t_plyr = mlx_xpm_file_to_image(game->mlx, "raycast/test/plyr.xpm", &size, &size);
	game->t_floor = mlx_xpm_file_to_image(game->mlx, "raycast/test/floor.xpm", &size, &size);
	game->t_wall = mlx_xpm_file_to_image(game->mlx, "raycast/test/wall.xpm", &size, &size);
	game->t_south = mlx_xpm_file_to_image(game->mlx, "raycast/test/wall.xpm", &size, &size);
	if (!game->t_plyr || !game->t_floor || !game->t_wall || !game->t_south)
	{
		printf("ERROR.. NO TEXTURES FOUND");
		exit_game(game);
	}
}

void	minimap_init(t_game *game)
{
	import_sources(game);
	print_minimap(game);
}
