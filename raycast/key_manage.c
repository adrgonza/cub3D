/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:01:37 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/06 12:15:22 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	key_actions(t_game *game)
{
	float	move_step;
	float	new_x;
	float	new_y;
	float angle;

	angle = game->p_angle * PI / 180.0f;
	move_step =  0.6f;
	if (game->keys->w == 1)
	{
		new_x = game->p_x + cos(angle) * move_step;
		new_y = game->p_y + sin(angle) * move_step;
		if (check_map(game, new_y, new_x))
		{
			game->p_x = new_x;
			game->p_y = new_y;
		}
	}
	if (game->keys->s == 1)
	{
		new_x = game->p_x - cos(angle) * move_step;
		new_y = game->p_y - sin(angle) * move_step;
		if (check_map(game, new_y, new_x))
		{
			game->p_x = new_x;
			game->p_y = new_y;
		}
	}
	if (game->keys->a == 1)
	{
		new_x = game->p_x - cos(angle + PI / 2) * move_step;
		new_y = game->p_y - sin(angle + PI / 2) * move_step;
		if (check_map(game, new_y, new_x))
		{
			game->p_x = new_x;
			game->p_y = new_y;
		}
	}
	if (game->keys->d == 1)
	{
		new_x = game->p_x + cos(angle + PI / 2) * move_step;
		new_y = game->p_y + sin(angle + PI / 2) * move_step;
		if (check_map(game, new_y, new_x))
		{
			game->p_x = new_x;
			game->p_y = new_y;
		}
	}
	if (game->keys->left == 1)
	{
		game->p_angle -= 1.9f;
		if (game->p_angle < 0.0f)
			game->p_angle += 360.0f;
	}
	if (game->keys->right == 1)
	{
		game->p_angle += 1.9f;
		if (game->p_angle >= 360.0f)
			game->p_angle -= 360.0f;
	}
	return (1);
}

int	key_press(int key, t_game *game)
{
	if (key == K_ESC)
		exit_game(game);
	if (key == 13)
		game->keys->w = 1;
	if (key == 1)
		game->keys->s = 1;
	if (key == 0)
		game->keys->a = 1;
	if (key == 2)
		game->keys->d = 1;
	if (key == 123)
		game->keys->left = 1;
	if (key == 124)
		game->keys->right = 1;
	return (0);
}

int key_released(int key, t_game *game)
{
	if (key == 13)
		game->keys->w = 0;
	if (key == 1)
		game->keys->s = 0;
	if (key == 0)
		game->keys->a = 0;
	if (key == 2)
		game->keys->d = 0;
	if (key == 123)
		game->keys->left = 0;
	if (key == 124)
		game->keys->right = 0;
	return (0);
}
