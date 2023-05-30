/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:30:26 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/30 18:31:20 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	game_loop(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	key_actions(game);
	print_minimap(game);
	draw_line(game);
	draw_square(game);
	draw_rays(game, game->rays);
	return (0);
}

void	init_data(t_game *game, t_cubdat *cubdat, t_keys *keys, t_rays *rays)
{
	game->mlx = mlx_init();
	game->wido = mlx_new_window(game->mlx, 1080, 720, "Midland v0.01");
	game->cubdat = cubdat;
	game->keys = keys;
	game->rays = rays;
	game->map = cubdat->map;
	game->p_x = cubdat->p_pos_x;
	game->p_y = cubdat->p_pos_y;
	game->keys->w = 0;
	game->keys->s = 0;
	game->keys->a = 0;
	game->keys->d = 0;
	game->keys->left = 0;
	game->keys->right = 0;
}

void	raycast(t_cubdat *cubdat)
{
	t_keys	keys;
	t_game	game;
	t_rays	rays;

	init_data(&game, cubdat, &keys, &rays);
	minimap_init(&game);
	mlx_hook(game.wido, 2, 1L << 0, key_press, &game);
	mlx_key_hook(game.wido, key_released, &game);
	mlx_hook(game.wido, 17, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, game_loop, (void *)&game);
	mlx_loop(game.mlx);
}
