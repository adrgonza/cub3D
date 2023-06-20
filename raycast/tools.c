/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:44:18 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/20 23:23:59 by adrgonza         ###   ########.fr       */
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

void	import_textures(t_game *g, t_cubdat *c)
{
	int	tx_h;
	int	tx_w;
	int	i;

	g->img = mlx_new_image(g->mlx, 1080, 720);
	g->img_data = mlx_get_data_addr(g->img,
			&g->img_bpp, &g->img_size, &g->img_end);
	g->txt[0] = mlx_xpm_file_to_image(g->mlx, c->no_route, &tx_w, &tx_h);
	g->txt[1] = mlx_xpm_file_to_image(g->mlx, c->ea_route, &tx_w, &tx_h);
	g->txt[2] = mlx_xpm_file_to_image(g->mlx, c->so_route, &tx_w, &tx_h);
	g->txt[3] = mlx_xpm_file_to_image(g->mlx, c->we_route, &tx_w, &tx_h);
	if (!g->txt[0] || !g->txt[1] || !g->txt[2] || !g->txt[3])
	{
		printf("Error.. No txt found\n");
		exit_game(g);
	}
	i = -1;
	while (++i < 4)
		g->txt_data[i] = (int *)mlx_get_data_addr(g->txt[i],
				&g->img_bpp, &g->img_size, &g->img_end);
}

void	init_data(t_game *g, t_cubdat *c, t_keys *keys)
{
	int	y;
	int	x;

	ft_bzero(g, sizeof(*g));
	g->mlx = mlx_init();
	g->window = mlx_new_window(g->mlx, 1080, 720, "Midland v0.31");
	g->cubdat = c;
	g->keys = keys;
	g->map = c->map;
	g->p_x = c->p_pos_x * 16;
	g->p_y = c->p_pos_y * 16;
	g->prevmouse_x = -1;
	import_textures(g, c);
}

int	exit_game(t_game *g)
{
	t_cubdat	*c;

	c = g->cubdat;
	mlx_destroy_image(g->mlx, g->img);
	mlx_destroy_window(g->mlx, g->window);
	exit(0);
}
