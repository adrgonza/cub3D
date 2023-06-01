/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/02 00:50:50 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw3d(t_game *game, float px, float py, float distance)
{


}

void	draw_sky_floor(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while(++y < 360)
	{
		x = 0;
		while (x < 1080)
			mlx_pixel_put(game->mlx, game->wido, x++, y, 0xFFFFFF);
	}
	y = 359;
	while(++y < 720)
	{
		x = 0;
		while (x < 1080)
			mlx_pixel_put(game->mlx, game->wido, x++, y, 0x99999);
	}
}

void draw_rays(t_game *game)
{
	float radian;
	float p_x;
	float p_y;

	radian = game->p_angle * (PI / 180);
	p_x = game->p_x;
	p_y = game->p_y;

	for (int column = 0; column < 1080; column++)
	{
		float angle = radian + atan((column - 540) / 320.0);

		float distance = 0.0;
		float delta_x = cos(angle);
		float delta_y = sin(angle);

		while (game->map[(int)p_y / 16][(int)p_x / 16] != 1)
		{
			p_x += delta_x;
			p_y += delta_y;
			distance += 0.01;
		}

		float wall_height = (720 / distance) * 0.1;
		int wall_start = (720 - wall_height) / 2;
		int wall_end = wall_start + wall_height;

		for (int y = 0; y < 720; y++)
		{
			if (y < wall_start)
				mlx_pixel_put(game->mlx, game->wido, column, y, 0x0000FF); // Cielo (azul)
			else if (y >= wall_start && y <= wall_end)
				mlx_pixel_put(game->mlx, game->wido, column, y, 0x000000); // Pared (blanco)
			else
				mlx_pixel_put(game->mlx, game->wido, column, y, 0x00FF00); // Suelo (verde)
		}

		p_x = game->p_x;
		p_y = game->p_y;
	}
}


