/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:44:18 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/21 15:57:43 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_sky_floor(t_game *g)
{
	int	y;
	int	x;
	int	position;

	g->img_data = mlx_get_data_addr(g->img,
			&g->img_bpp, &g->img_size, &g->img_end);
	y = -1;
	while (++y < 720)
	{
		x = -1;
		while (++x < 1080)
		{
			position = (y * g->img_size) + (x * (g->img_bpp / 8));
			g->img_data[position] = (unsigned char)g->cubdat->c_col.b;
			g->img_data[position + 1] = (unsigned char)g->cubdat->c_col.g;
			g->img_data[position + 2] = (unsigned char)g->cubdat->c_col.r;
			if (y > 359)
			{
				g->img_data[position] = (unsigned char)g->cubdat->f_col.b;
				g->img_data[position + 1] = (unsigned char)g->cubdat->f_col.g;
				g->img_data[position + 2] = (unsigned char)g->cubdat->f_col.r;
			}
		}
	}
}

int	check_map(t_game *g, float y, float x)
{
	if ((int)y / 16 <= 0 || (int)y / 16 > g->cubdat->map_height - 2)
		return (0);
	if ((int)x / 16 <= 0 || (int)x / 16 > g->cubdat->map_width - 3)
		return (0);
	if (g->map[(int)y / 16][(int)x / 16] > 0)
		return (0);
	return (1);
}

int	mouse_move(int x, int y, t_game *game)
{
	float	delta_angle;

	if (game->prevmouse_x != -1)
	{
		delta_angle = (x - game->prevmouse_x) * 0.2f;
		game->p_angle += delta_angle;
		if (game->p_angle < 0.0f)
			game->p_angle += 360.0f;
		if (game->p_angle >= 360.0f)
			game->p_angle -= 360.0f;
	}
	game->prevmouse_x = x;
	(void)y;
	return (0);
}

int	exit_game(t_game *g)
{
	t_cubdat	*c;

	c = g->cubdat;
	mlx_destroy_image(g->mlx, g->img);
	mlx_destroy_window(g->mlx, g->window);
	exit(0);
}
