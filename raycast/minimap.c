/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:36:36 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/25 15:08:36 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int check_minimap(t_game *game)
{
	//t_aux aux;
	//aux = game->map etc....
	//if (aux->map[y][x] == '1')
	return(1);
}

void	print_minimap(t_game *game)
{
	int	**map;
	int i;
	int j;
	int x = 1050;
	int y = 25;

	if (!check_minimap(game))
		return ;
	i = -1;
	while(++i <= 7)
	{
		j = -1;
		y = 25;
		while(++j <= 7)
		{
			mlx_put_image_to_window(game->mlx, game->wido, game->t_west, x, y);
			y += 8;
		}
		x -= 8;
	}
}

void	import_sources(t_game *game)
{
	int size;

	game->t_north = mlx_xpm_file_to_image(game->mlx, "raycast/test/floor.xpm", &size, &size);
	game->t_east = mlx_xpm_file_to_image(game->mlx, "raycast/test/wall.xpm", &size, &size);
	game->t_west = mlx_xpm_file_to_image(game->mlx, "raycast/test/colle.xpm", &size, &size);
	game->t_south = mlx_xpm_file_to_image(game->mlx, "raycast/test/plyr.xpm", &size, &size);
	if (!game->t_north || !game->t_east || !game->t_west || !game->t_south)
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
