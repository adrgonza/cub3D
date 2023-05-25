/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:30:26 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/25 15:07:44 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	init_data(t_game *game)
{
	game->mlx = mlx_init();
	game->wido = mlx_new_window(game->mlx, 1080, 720, "Midland v0.01");
}

int	key_actions(int key, t_game *game)
{
	if (key == K_ESC)
		exit_game(game);
	return (1);
}

void	game_launch(t_game	*game)
{
	(void)game;
}

void	raycast()
{
	t_game game;

	init_data(&game);
	minimap_init(&game);
	game_launch(&game);
	mlx_key_hook(game.wido, key_actions, &game);
	mlx_hook(game.wido, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
}
