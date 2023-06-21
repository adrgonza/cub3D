/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:30:26 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/21 15:24:24 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	game_loop(void *data)
{
	t_game	*game;

	game = (t_game *)data;
	key_actions(game);
	draw_sky_floor(game);
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (0);
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
	g->p_x = (c->p_pos_x + 0.5) * 16;
	g->p_y = (c->p_pos_y + 0.5) * 16;
	g->prevmouse_x = -1;
	if (c->play_orient == 'N')
		g->p_angle = 270;
	if (c->play_orient == 'E')
		g->p_angle = 0;
	if (c->play_orient == 'W')
		g->p_angle = 180;
	if (c->play_orient == 'S')
		g->p_angle = 90;
	import_textures(g, c);
}

void	raycast(t_cubdat *cubdat)
{
	t_keys	keys;
	t_game	game;

	init_data(&game, cubdat, &keys);
	mlx_hook(game.window, 2, 1L << 0, key_press, &game);
	mlx_key_hook(game.window, key_released, &game);
	mlx_hook(game.window, 6, 1L << 6, mouse_move, &game);
	mlx_loop_hook(game.mlx, game_loop, (void *)&game);
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
}
