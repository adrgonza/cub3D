/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:30:26 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/26 15:01:50 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	init_data(t_game *game, t_cubdat *cubdat)
{
	game->mlx = mlx_init();
	game->wido = mlx_new_window(game->mlx, 1080, 720, "Midland v0.01");
	game->cubdat = cubdat;
	game->plyr_x = cubdat->p_pos_x;
	game->plyr_y = cubdat->p_pos_y;
	game->map_posx = 960;
	game->map_posy = 25;
}

int	key_actions(int key, t_game *game)
{
	if (key == K_ESC)
		exit_game(game);
	if (key == 13 && check_map(game, game->plyr_y - 1, game->plyr_x))
		game->plyr_y--;
	if (key == 1 && check_map(game, game->plyr_y + 1, game->plyr_x))
		game->plyr_y++;
	if (key == 0 && check_map(game, game->plyr_y, game->plyr_x - 1))
		game->plyr_x--;
	if (key == 2 && check_map(game, game->plyr_y, game->plyr_x + 1))
		game->plyr_x++;
	print_minimap(game);
	return (1);
}

void	game_launch(t_game	*game)
{
	(void)game;
}

void	raycast(t_cubdat *cubdat)
{
	t_game game;

	init_data(&game, cubdat);
	minimap_init(&game);
	game_launch(&game);
	mlx_key_hook(game.wido, key_actions, &game);
	mlx_hook(game.wido, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
}
