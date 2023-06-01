/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/01 03:40:50 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_sky_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while(y < 360)
	{
		x = 0;
		while (x < 1080)
			mlx_pixel_put(game->mlx, game->wido, x++, y, 0xFFFFFF);
		y++;
	}
	while(y < 720)
	{
		x = 0;
		while (x < 1080)
			mlx_pixel_put(game->mlx, game->wido, x++, y, 0x99999);
		y++;
	}
}

void	draw_rays(t_game *game)
{
	int		i;
	float	radian;
	float	p_x;
	float	p_y;

	radian = game->p_angle * (PI / 180);
	p_x = game->p_x;
	p_y = game->p_y;
	i =  -19;
	while (i++ <  20)
	{
		while (game->map[(int)p_y / 16][(int)p_x / 16] != 1)
		{
			p_x += cos(radian + (i / 40.0));
			p_y += sin(radian + (i / 40.0));
			mlx_pixel_put(game->mlx, game->wido, p_x, p_y, 0x99099);
		}
		p_x = game->p_x;
		p_y = game->p_y;
	}
}
void	draw_img(t_game *game)
{

}

void	draw_3d(t_game *game)
{/*
	int	y;
	int	x;

	y = 0;
	while(game->map[y][0] < )
	{
		x = 0;
		while (game->map[y][x] < game->cubdat->map_width)
		{
			if (game->map[y][x])
				//draw_img(game);
			x++;
		}
		y++;
	}*/
}
