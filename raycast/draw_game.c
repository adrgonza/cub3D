/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/21 19:00:18 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	determine_wall_orientation(t_game *g, t_rays *r, float ray_angle)
{
	if (r->cell_x < 0.0007 || r->cell_x > 0.9993)
	{
		if ((int)r->p_y / 16 > 0 && (int)r->p_x / 16 > 0
			&& (int)r->p_x / 16 < g->cubdat->map_width - 5
			&& (int)r->p_x / 16 < g->cubdat->map_height - 2
			&& g->map[(int)r->p_y / 16][((int)r->p_x / 16) + 1] == 1
			&& g->map[(int)r->p_y / 16][((int)r->p_x / 16) - 1]
			&& g->map[(int)r->p_y / 16][((int)r->p_x / 16) - 1] == 1)
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

void	render_wall_texture(t_game *g, t_rays *rays, int y)
{
	int		tex_x;
	int		tex_y;
	int		*txt_data;

	tex_y = (int)(64 * ((y - rays->wall_start) / rays->wall_height));
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

void	render_walls(t_game *g, t_rays *r)
{
	int		y;

	r->wall_height = (720 / (r->distance * cos(r->angle - r->radian)))
		* 0.001;
	r->wall_start = (720 - r->wall_height) / 2;
	r->wall_end = r->wall_start + r->wall_height;
	y = -1;
	while (++y < 720)
	{
		if (y >= r->wall_start && y <= r->wall_end && r->cord > 0
			&& r->cord < 5)
			render_wall_texture(g, r, y);
	}
	r->p_x = g->p_x;
	r->p_y = g->p_y;
}

void	calculate_ray_path(t_game *g, t_rays *rays)
{
	float	ray_angle;

	while ((int)rays->p_x / 16 < g->cubdat->map_width - 2
		&& (int)rays->p_x / 16 > 0 && (int)rays->p_y / 16 > 0
		&& (int)rays->p_y / 16 < g->cubdat->map_height
		&& g->map[(int)rays->p_y / 16][(int)rays->p_x / 16] != 1)
	{
		rays->p_x += rays->delta_x * 0.01;
		rays->p_y += rays->delta_y * 0.01;
		rays->distance += sqrt(rays->delta_x * rays->delta_x + rays->delta_y
				* rays->delta_y) * 0.0000009;
	}
	rays->cell_x = (rays->p_x / 16) - (int)(rays->p_x / 16);
	rays->cell_y = (rays->p_y / 16) - (int)(rays->p_y / 16);
	ray_angle = rays->angle * (180 / PI);
	ray_angle = fmod(ray_angle, 360.0);
	if (ray_angle < 0)
		ray_angle += 360.0;
	rays->cord = determine_wall_orientation(g, rays, ray_angle);
	render_walls(g, rays);
}

void	cast_rays(t_game *g)
{
	t_rays	rays;

	rays.cord = 1;
	rays.radian = g->p_angle * (PI / 180);
	rays.p_x = g->p_x;
	rays.p_y = g->p_y;
	rays.column = -1;
	rays.img_data = (int *)g->img_data;
	while (++rays.column < 1080)
	{
		rays.angle = rays.radian + 0.95 * atan((rays.column - 540) / 480.0);
		rays.distance = 0.0;
		rays.delta_x = cos(rays.angle);
		rays.delta_y = sin(rays.angle);
		calculate_ray_path(g, &rays);
	}
}
