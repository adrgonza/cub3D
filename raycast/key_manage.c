/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:01:37 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/20 23:11:40 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	key_tools2(t_game *game)
{
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
}

void	key_tools(t_game *game)
{
	if (game->keys->a == 1)
	{
		game->k_new_x = game->p_x - cos(game->k_angle + PI / 2) * game->k_fas;
		game->k_new_y = game->p_y - sin(game->k_angle + PI / 2) * game->k_fas;
		if (check_map(game, game->k_new_y, game->k_new_x))
		{
			game->p_x = game->k_new_x;
			game->p_y = game->k_new_y;
		}
	}
	if (game->keys->d == 1)
	{
		game->k_new_x = game->p_x + cos(game->k_angle + PI / 2) * game->k_fas;
		game->k_new_y = game->p_y + sin(game->k_angle + PI / 2) * game->k_fas;
		if (check_map(game, game->k_new_y, game->k_new_x))
		{
			game->p_x = game->k_new_x;
			game->p_y = game->k_new_y;
		}
	}
}

void	key_actions(t_game *game)
{
	game->k_angle = game->p_angle * PI / 180.0f;
	game->k_fas = 0.35f;
	if (game->keys->w == 1)
	{
		game->k_new_x = game->p_x + cos(game->k_angle) * game->k_fas;
		game->k_new_y = game->p_y + sin(game->k_angle) * game->k_fas;
		if (check_map(game, game->k_new_y, game->k_new_x))
		{
			game->p_x = game->k_new_x;
			game->p_y = game->k_new_y;
		}
	}
	if (game->keys->s == 1)
	{
		game->k_new_x = game->p_x - cos(game->k_angle) * game->k_fas;
		game->k_new_y = game->p_y - sin(game->k_angle) * game->k_fas;
		if (check_map(game, game->k_new_y, game->k_new_x))
		{
			game->p_x = game->k_new_x;
			game->p_y = game->k_new_y;
		}
	}
	key_tools(game);
	key_tools2(game);
}

int	key_press(int key, t_game *game)
{
	if (key == K_ESC)
		exit_game(game);
	if (key == K_W)
		game->keys->w = 1;
	if (key == K_S)
		game->keys->s = 1;
	if (key == K_A)
		game->keys->a = 1;
	if (key == K_D)
		game->keys->d = 1;
	if (key == 123)
		game->keys->left = 1;
	if (key == 124)
		game->keys->right = 1;
	return (0);
}

int	key_released(int key, t_game *game)
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
