/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:30:26 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/02 01:04:15 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	game_loop(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	key_actions(game);
	draw_sky_floor(game);
	//print_minimap(game);
	draw_rays(game);
	return (0);
}

void	raycast(t_cubdat *cubdat)
{
	t_keys	keys;
	t_game	game;

	init_data(&game, cubdat, &keys);
	minimap_init(&game);
	mlx_hook(game.wido, 2, 1L << 0, key_press, &game);
	mlx_key_hook(game.wido, key_released, &game);
	mlx_hook(game.wido, 17, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, game_loop, (void *)&game);
	mlx_loop(game.mlx);
}
