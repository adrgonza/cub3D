/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:30:26 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/05 14:18:22 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	game_loop(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	key_actions(game);
	mlx_put_image_to_window(game->mlx, game->wido, game->background, 0, 0);
	draw_rays(game);
	print_minimap(game);
	return (0);
}

void	raycast(t_cubdat *cubdat)
{
	t_keys	keys;
	t_game	game;

	init_data(&game, cubdat, &keys); /* int all data */
	mlx_hook(game.wido, 2, 1L << 0, key_press, &game); /* when a key is pressed */
	mlx_key_hook(game.wido, key_released, &game); /* when a key is released */
	mlx_loop_hook(game.mlx, game_loop, (void *)&game); /* game loop */
	mlx_hook(game.wido, 17, 0, exit_game, &game); /* a hook who manage red cross window */
	mlx_loop(game.mlx); /* mlx loop */
}
