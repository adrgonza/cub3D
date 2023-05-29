/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:30:26 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/29 20:09:56 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"


void	init_data(t_game *game, t_cubdat *cubdat)
{
	game->mlx = mlx_init();
	game->wido = mlx_new_window(game->mlx, 1080, 720, "Midland v0.01");
	game->cubdat = cubdat;
	game->map = cubdat->map;
	game->p_x = cubdat->p_pos_x;
	game->p_y = cubdat->p_pos_y;
}

int key_released(int key)
{
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == K_ESC)
		exit_game(game);
	if (key == 13 && check_map(game, game->p_y - 1, game->p_x))
		game->p_y -= 2.5;
	if (key == 1 && check_map(game, game->p_y + 1, game->p_x))
		game->p_y += 2.5;
	if (key == 0 && check_map(game, game->p_y, game->p_x - 1))
		game->p_x -= 2.5;
	if (key == 2 && check_map(game, game->p_y, game->p_x + 1))
		game->p_x += 2.5;
	if (key == 123)
	{
		game->p_angle -= -1;
		if (game->p_angle < 0)
			game->p_angle += 2 * PI;
		game->p_dx = cos(game->p_angle) * 5;
		game->p_dy = sin(game->p_angle) * 5;
	}
	if (key == 124)
	{
		game->p_angle += 1;
		if (game->p_angle > 0)
			game->p_angle -= 2 * PI;
		return (game->p_dx = cos(game->p_angle) * 5, game->p_dy = sin(game->p_angle) * 5, 1);
	}
	return (1);
}

void	game_launch(t_game	*game)
{

}

void	raycast(t_cubdat *cubdat)
{
	t_game game;

	init_data(&game, cubdat);
	minimap_init(&game);
	game_launch(&game);
	mlx_key_hook(game.wido, key_released, NULL);
	mlx_hook(game.wido, 2, 1L << 0, key_press, &game);
	mlx_hook(game.wido, 17, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, print_minimap, (void *)&game);
	mlx_loop(game.mlx);
}
