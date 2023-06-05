/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/05 14:34:17 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_sky_floor(t_game *game)
{
	int x;
	int y;

	y = -1;
	while (++y < 360)
	{
		for (x = 0; x < 1080; x++)
		{
			int position = (y * game->l_size) + (x * (game->bpp / 8));
			game->bkgrn_data[position] = 255; // Asignar componente rojo (0-255)
			game->bkgrn_data[position + 1] = 100; // Asignar componente verde (0-255)
			game->bkgrn_data[position + 2] = 100; // Asignar componente azul (0-255)
		}
	}
	y = 359;
	while (++y < 720)
	{
		for (x = 0; x < 1080; x++)
		{
			int position = (y * game->l_size) + (x * (game->bpp / 8));
			game->bkgrn_data[position] = 100; // Asignar componente rojo (0-255)
			game->bkgrn_data[position + 1] = 100; // Asignar componente verde (0-255)
			game->bkgrn_data[position + 2] = 100; // Asignar componente azul (0-255)
		}
	}
}

void draw_rays(t_game *game)
{
	int column;
	float radian;
	float p_x;
	float p_y;

	radian = game->p_angle * (PI / 180);
	p_x = game->p_x;
	p_y = game->p_y;
	column = -1;
	while (++column < 1080)
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
		float wall_height = (720 / distance) * 0.12;
		int wall_start = (720 - wall_height) / 2;
		int wall_end = wall_start + wall_height;
		p_y = -1;
		while (++p_y < 720)
			if (p_y >= wall_start && p_y <= wall_end)
				mlx_pixel_put(game->mlx, game->wido, column, p_y, 0x8b0000); // Pared (blanco)
		p_x = game->p_x;
		p_y = game->p_y;
	}
}


