/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/18 16:29:22 by adrgonza         ###   ########.fr       */
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
	while (i++ < 8)
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
			game->background_data[position] = (unsigned char)game->cubdat->c_col.b; // Asignar componente rojo (0-255)
			game->background_data[position + 1] = (unsigned char)game->cubdat->c_col.g; // Asignar componente verde (0-255)
			game->background_data[position + 2] = (unsigned char)game->cubdat->c_col.r; // Asignar componente azul (0-255)
		}
	}
	y = 359;
	while (++y < 720)
	{
		for (x = 0; x < 1080; x++)
		{
			int position = (y * game->background_size) + (x * (game->background_bpp / 8));
			game->background_data[position] = (unsigned char)game->cubdat->f_col.b; // Asignar componente rojo (0-255)
			game->background_data[position + 1] = (unsigned char)game->cubdat->f_col.g; // Asignar componente verde (0-255)
			game->background_data[position + 2] = (unsigned char)game->cubdat->f_col.r; // Asignar componente azul (0-255)
		}
	}
}

int	get_wall_orientation(float p_y, float p_x, float angle, t_game *game)
{
	float	ray_angle;
	float cell_x = (p_x / 16) - (int)(p_x / 16);
	float cell_y = (p_y / 16) - (int)(p_y / 16);

	ray_angle = angle * (180 / PI); // convert radians to degrees
	ray_angle = fmod(ray_angle, 360.0);
	if (ray_angle < 0)
		ray_angle += 360.0;
	if (cell_x < 0.0007 || cell_x > 0.9993)
	{
		if (game->map[(int)p_y / 16][((int)p_x / 16) + 1] && game->map[(int)p_y / 16][((int)p_x / 16) + 1] == 1 && (int)p_x / 16 > 0 && game->map[(int)p_y / 16][((int)p_x / 16) - 1] && game->map[(int)p_y / 16][((int)p_x / 16) - 1] == 1)
		{
			if (ray_angle < 180)
				 return (4);
			return (2);
		}
		if (ray_angle >= 90 && ray_angle <= 270)
			return (3);
		return (1);
	}
	else
	{
		if (ray_angle < 180)
			return (4);
		return (2);
	}
	return (1);
}

void	print_walls(t_game *game, t_rays *rays)
{
	int		tex_x, tex_y;
	float wall_height = (720 / (rays->distance * cos(rays->angle - rays->radian))) * 0.001;
	int wall_start = (720 - wall_height) / 2;
	int wall_end = wall_start + wall_height;
	int y = -1;
	int		*texture_data;
	while (++y < 720)
	{
		if (y >= wall_start && y <= wall_end && rays->cord > 0 && rays->cord < 5)
		{
			tex_y = (int)(64 * ((y - wall_start) / wall_height));
			if (rays->cord % 2 == 0)
				tex_x = (int)(64 * ((rays->p_x / 16) - (int)(rays->p_x / 16)));
			else
			 	tex_x = (int)(64 * ((rays->p_y / 16) - (int)(rays->p_y / 16)));
			if (tex_x < 0)
				tex_x = 0;
			if (tex_x > 63)
				tex_x = 63;
			if (tex_y > 63)
				tex_y = 63;
			if (tex_y < 0)
				tex_y = 0;
			texture_data = (int *)game->texture_data[rays->cord - 1];
			rays->color = texture_data[tex_y * 64 + tex_x];
			rays->background_data[y * 1080 + rays->column] = mlx_get_color_value(game->mlx, rays->color);
		}
	}
}

void draw_rays(t_game *game)
{
	t_rays	rays;

	rays.cord = 1;
	rays.radian = game->p_angle * (PI / 180);
	rays.p_x = game->p_x;
	rays.p_y = game->p_y;
	rays.column = -1;
	rays.background_data = (int *)game->background_data; // Get the data address at the beginning
	while (++rays.column < 1080)
	{
		rays.angle = rays.radian + 0.95 * atan((rays.column - 540) / 480.0); // change fov (not recommended)
		rays.distance = 0.0;
		rays.delta_x = cos(rays.angle);
		rays.delta_y = sin(rays.angle);
		while ((int)rays.p_x / 16 < game->cubdat->map_width - 2 && (int)rays.p_x / 16 > 0 &&  (int)rays.p_y / 16 >= 0 && (int)rays.p_y / 16 < game->cubdat->map_height && game->map[(int)rays.p_y / 16][(int)rays.p_x / 16] != 1) //&& (int)rays.p_y / 16 > 0 && (int)rays.p_y / 16 < game->cubdat->map_height && (int)rays.p_x / 16 > 0 && (int)rays.p_x / 16 < game->cubdat->map_width);
		{
			rays.p_x += rays.delta_x * 0.01;
			rays.p_y += rays.delta_y * 0.01;
			rays.distance += sqrt(rays.delta_x * rays.delta_x + rays.delta_y * rays.delta_y) * 0.0000009;
		}
		rays.cord = get_wall_orientation(rays.p_y, rays.p_x, rays.angle, game);
		print_walls(game, &rays);
		rays.p_x = game->p_x;
		rays.p_y = game->p_y;
	}
}


