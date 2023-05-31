/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/01 00:38:34 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

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
		printf("%d", i);
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
