/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/19 18:14:04 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_line(t_game *g)
{
	float	radian;
	int		x;
	int		y;
	int		i;

	radian = g->p_angle * (PI / 180); /* converts de angle to a radians */
	i = -1;
	while (i++ < 8)
	{
		x = g->p_x + i * cos(radian);
		y = g->p_y + i * sin(radian);
		mlx_pixel_put(g->mlx, g->window, x, y, 0xFFFFFF);
	}
}

void	draw_square(t_game *g)
{
	int	start_x;
	int	start_y;
	int	x;
	int	y;

	start_x = g->p_x - 2.5;
	start_y = g->p_y - 2.5;
	y = start_y - 0.5;
	while (++y < start_y + 5)
	{
		x = start_x - 0.5;
		while (++x < start_x + 5)
			mlx_pixel_put(g->mlx, g->window, x, y, 0xFFFFFF);
	}
}

void	draw_sky_floor(t_game *g)
{
	int	y;
	int	x;
	int	position;

	g->img_data = mlx_get_data_addr(g->img_img,
			&g->img_bpp, &g->img_size, &g->img_endian);
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

int	get_wall_orientation(float p_y, float p_x, float angle, t_game *g)
{
	float	ray_angle;
	float	cell_x;
	float	cell_y;

	cell_x = (p_x / 16) - (int)(p_x / 16);
	cell_y = (p_y / 16) - (int)(p_y / 16);
	ray_angle = angle * (180 / PI); // convert radians to degrees
	ray_angle = fmod(ray_angle, 360.0);
	if (ray_angle < 0)
		ray_angle += 360.0;
	if (cell_x < 0.0007 || cell_x > 0.9993)
	{
		if ((int)p_y / 16 >= 0 && (int)p_x / 16 > 0 && (int)p_x
			/ 16 < g->cubdat->map_width - 2 && g->map[(int)p_y / 16][((int)p_x
				/ 16) + 1] == 1 && g->map[(int)p_y / 16][((int)p_x / 16) - 1]
			&& g->map[(int)p_y / 16][((int)p_x / 16) - 1] == 1)
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

void	print_walls(t_game *g, t_rays *rays)
{
	float	wall_height;
	int		wall_start;
	int		wall_end;
	int		y;
	int		*txt_data;

	int tex_x, tex_y;
	wall_height = (720 / (rays->distance * cos(rays->angle - rays->radian)))
		* 0.001;
	wall_start = (720 - wall_height) / 2;
	wall_end = wall_start + wall_height;
	y = -1;
	while (++y < 720)
	{
		if (y >= wall_start && y <= wall_end && rays->cord > 0
			&& rays->cord < 5)
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
			txt_data = (int *)g->txt_data[rays->cord - 1];
			rays->color = txt_data[tex_y * 64 + tex_x];
			rays->img_data[y * 1080
				+ rays->column] = mlx_get_color_value(g->mlx, rays->color);
		}
	}
}

void	draw_rays(t_game *g)
{
	t_rays	rays;

	rays.cord = 1;
	rays.radian = g->p_angle * (PI / 180);
	rays.p_x = g->p_x;
	rays.p_y = g->p_y;
	rays.column = -1;
	rays.img_data = (int *)g->img_data; // Get the data address at the beginning
	while (++rays.column < 1080)
	{
		rays.angle = rays.radian + 0.95 * atan((rays.column - 540) / 480.0);
			// change fov (not recommended)
		rays.distance = 0.0;
		rays.delta_x = cos(rays.angle);
		rays.delta_y = sin(rays.angle);
		while ((int)rays.p_x / 16 < g->cubdat->map_width - 2 && (int)rays.p_x
			/ 16 > 0 && (int)rays.p_y / 16 > 0 && (int)rays.p_y
			/ 16 < g->cubdat->map_height && g->map[(int)rays.p_y
			/ 16][(int)rays.p_x / 16] != 1)
		{
			rays.p_x += rays.delta_x * 0.01;
			rays.p_y += rays.delta_y * 0.01;
			rays.distance += sqrt(rays.delta_x * rays.delta_x + rays.delta_y
					* rays.delta_y) * 0.0000009;
		}
		rays.cord = get_wall_orientation(rays.p_y, rays.p_x, rays.angle, g);
		print_walls(g, &rays);
		rays.p_x = g->p_x;
		rays.p_y = g->p_y;
	}
}
