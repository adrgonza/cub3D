/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:44:18 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/20 03:44:04 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

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

	ft_bzero(g, sizeof(*g)); /* init all vars */
	g->mlx = mlx_init(); /* mlx init */
	g->window = mlx_new_window(g->mlx, 1080, 720, "Midland v0.31");
	g->cubdat = c; /* save de adress of the parser struct */
	g->keys = keys; /* save the adres for keys structure */
	g->map = c->map; /* get the map */
	g->p_x = c->p_pos_x * 16; /* player start position x */
	g->p_y = c->p_pos_y * 16; /* player start position x */
	g->prevmouse_x = -1; /* for mouse */
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
