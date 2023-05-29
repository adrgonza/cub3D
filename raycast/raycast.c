/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:30:26 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/30 01:12:06 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"


void	init_data(t_game *game, t_cubdat *cubdat, t_keys *keys)
{
	game->mlx = mlx_init();
	game->wido = mlx_new_window(game->mlx, 1080, 720, "Midland v0.01");
	game->cubdat = cubdat;
	game->keys = keys;
	game->map = cubdat->map;
	game->p_x = cubdat->p_pos_x;
	game->p_y = cubdat->p_pos_y;
	game->p_dx = cos(game->p_angle) * 5;
	game->p_dy = sin(game->p_angle) * 5;
}

void	raycast(t_cubdat *cubdat)
{
	t_keys keys;
	t_game game;

	init_data(&game, cubdat, &keys);
	minimap_init(&game);
	mlx_key_hook(game.wido, key_released, NULL);
	mlx_hook(game.wido, 2, 1L << 0, key_press, &game);
	mlx_hook(game.wido, 2, 1L << 0, key_press, &game);
	mlx_hook(game.wido, 17, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, print_minimap, (void *)&game);
	mlx_loop(game.mlx);
}
