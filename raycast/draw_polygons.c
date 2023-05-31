/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_polygons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:54:46 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/31 16:54:04 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_line(t_game *game)
{
	float	radian;
	int		x;
	int		y;
	int		i;

	radian = game->p_angle * (PI / 180); /* converts de angle to a radians */
	i = -1;
	while (i++ < 10)
	{
		x = game->p_x + i * cos(radian);
		y = game->p_y + i * sin(radian);
		mlx_pixel_put(game->mlx, game->wido, x, y, 0xFFFFFF);
	}
}

void	draw_square(t_game *game)
{
	int start_x;
	int start_y;
	int x;
	int y;

	start_x = game->p_x - 2.5;
	start_y = game->p_y - 2.5;
	y = start_y - 0.5;
	while (++y < start_y + 5)
	{
		x = start_x - 0.5;
		while (++x < start_x + 5)
		{
			mlx_pixel_put(game->mlx, game->wido, x, y, 0xFFFFFF);
		}
	}
}
