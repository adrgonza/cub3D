/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:36:36 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/30 01:41:21 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	check_map(t_game *game, int y, int x)
{
	return (1);
}

void	print_minimap2(t_game *game, int i, int **map)
{
	int	j;

	j = -1;
	while(++j < game->cubdat->map_width - 1)
	{
		if (j < 0 || j > game->cubdat->map_width - 2 || i < 0 || i > game->cubdat->map_height - 1)
			mlx_put_image_to_window(game->mlx, game->wido, game->t_wall, game->map_posy, game->map_posx);
		else if (map[i][j] >= 1)
			mlx_put_image_to_window(game->mlx, game->wido, game->t_wall, game->map_posy, game->map_posx);
		else if (map[i][j] == -1)
			mlx_put_image_to_window(game->mlx, game->wido, game->t_south, game->map_posy, game->map_posx);
		else if (map[i][j] == 0)
			mlx_put_image_to_window(game->mlx, game->wido, game->t_floor, game->map_posy, game->map_posx);
		game->map_posy += 16;
	}
}

void	print_minimap(t_game *game)
{
	int	**map;
	int i;

	game->map_posx = 0;
	map = game->map;
	i = -1;
	while(++i < game->cubdat->map_height)
	{
		game->map_posy = 0;
		print_minimap2(game, i, map);
		game->map_posx += 16;
	}
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
