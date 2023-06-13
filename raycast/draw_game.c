/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/13 12:17:02 by adrgonza         ###   ########.fr       */
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
		mlx_pixel_put(game->mlx, game->window, x, y, 0xFFFFFF);
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
			mlx_pixel_put(game->mlx, game->window, x, y, 0xFFFFFF);
	}
}

void	draw_sky_floor(t_game *game)
{
	int x;
	int y;

	game->background_data = mlx_get_data_addr(game->background_img, &game->background_bpp, &game->background_size, &game->background_endian);
	y = -1;
	while (++y < 360)
	{
		for (x = 0; x < 1080; x++)
		{
			int position = (y * game->background_size) + (x * (game->background_bpp / 8));
			game->background_data[position] = (unsigned char)255; // Asignar componente rojo (0-255)
			game->background_data[position + 1] = (unsigned char)100; // Asignar componente verde (0-255)
			game->background_data[position + 2] = (unsigned char)100; // Asignar componente azul (0-255)
		}
	}
	y = 359;
	while (++y < 720)
	{
		for (x = 0; x < 1080; x++)
		{
			int position = (y * game->background_size) + (x * (game->background_bpp / 8));
			game->background_data[position] = 100; // Asignar componente rojo (0-255)
			game->background_data[position + 1] = 100; // Asignar componente verde (0-255)
			game->background_data[position + 2] = 100; // Asignar componente azul (0-255)
		}
	}
}

int	get_wall_orientation(float p_y, float p_x)
{
	float cell_x = (p_x / 16) - (int)(p_x / 16);
	float cell_y = (p_y / 16) - (int)(p_y / 16);
	printf("cell_y--%f\n", cell_y);
	printf("cell_x--%f\n", cell_x);
	if (cell_x < 0.5)
	{
		if (cell_y < 0.001)
			return (4);
		else
			return (1);
	}
	if (cell_x > 0.5)
	{
		if (cell_y < 0.001)
			return (4);
		else
			return (3);
	}
	return (0);
}

void draw_rays(t_game *game)
{
	int		cord;
	int		column;
	int		tex_x, tex_y;
	int		*texture_data;
	int		*background_data;
	int		color;
	float	radian;
	float	p_x;
	float	p_y;
	float	ray_angle;

	cord = 1;
	radian = game->p_angle * (PI / 180);
	p_x = game->p_x;
	p_y = game->p_y;
	column = -1;
	background_data = (int *)game->background_data; // Get the data address at the beginning
	while (++column < 1080)
	{
		float angle = radian + 0.95 * atan((column - 540) / 480.0); // change fov (not recommended)
		double distance = 0.0;
		float delta_x = cos(angle);
		float delta_y = sin(angle);
		while (game->map[(int)p_y / 16][(int)p_x / 16] != 1)
		{
			p_x += delta_x * 0.01;
			p_y += delta_y * 0.01;
			distance += sqrt(delta_x * delta_x + delta_y * delta_y) * 0.0000009;
		}
		float cell_x = (p_x / 16) - (int)(p_x / 16);
		float cell_y = (p_y / 16) - (int)(p_y / 16);
		ray_angle = angle * (180 / PI); // convert radians to degrees
		ray_angle = fmod(ray_angle, 360.0);
		if (ray_angle < 0)
			ray_angle += 360.0;
		printf("angle--%f\n", ray_angle);
		if (cell_x < 0.0007 || cell_x > 0.9993)
		{
			cord = 1;
			if (ray_angle >= 90 && ray_angle <= 270)
				cord = 3;
			if (game->map[(int)p_y / 16][((int)p_x / 16) + 1] == 1 && game->map[(int)p_y / 16][((int)p_x / 16) - 1])
			{
				cord = 2;
				if (ray_angle < 180)
					cord = 4;
			}
		}
		else
		{
			cord = 2;
			if (ray_angle < 180)
				cord = 4;
		}
		game->aux = cell_x;
		float wall_height = (720 / (distance * cos(angle - radian))) * 0.001;
		int wall_start = (720 - wall_height) / 2;
		int wall_end = wall_start + wall_height;
		int y = -1;
		while (++y < 720)
		{
			if (y >= wall_start && y <= wall_end && cord > 0 && cord < 5)
			{
				tex_y = (int)(64 * ((y - wall_start) / wall_height));
				if (cord % 2 == 0) // norte y sur
    				tex_x = (int)(64 * ((p_x / 16) - (int)(p_x / 16)));
				else // este y oeste
    			 	tex_x = (int)(64 * ((p_y / 16) - (int)(p_y / 16)));
				if (tex_x < 0) tex_x = 0;
				if (tex_x > 63) tex_x = 63;

				texture_data = (int *)game->texture_data[cord - 1];
				color = texture_data[tex_y * 64 + tex_x];
				background_data[y * 1080 + column] = mlx_get_color_value(game->mlx, color);
			}
		}
		p_x = game->p_x;
		p_y = game->p_y;
	}
}


