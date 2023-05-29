/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:01:37 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/30 01:08:56 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"



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
		game->p_angle -= 1.0f;
		if (game->p_angle < 0.0f)
			game->p_angle += 360.0f;
		/*game->p_angle -= -1;
		if (game->p_angle < 0)
			game->p_angle += 2 * PI;
		game->p_dx = cos(game->p_angle) * 5;
		game->p_dy = sin(game->p_angle) * 5;*/
	}
	if (key == 124)
	{
		game->p_angle += 1.0f;
		if (game->p_angle >= 360.0f)
			game->p_angle -= 360.0f;
		/*game->p_angle += 1;
		if (game->p_angle > 2 * PI)
			game->p_angle -= 2 * PI;
		return (game->p_dx = cos(game->p_angle) * 5, game->p_dy = sin(game->p_angle) * 5, 1);*/
	}
	return (1);
}

int key_released(int key)
{
	return (0);
}
