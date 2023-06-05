/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:44:18 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/05 14:19:48 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	init_data(t_game *game, t_cubdat *cubdat, t_keys *keys)
{
	ft_bzero(game, sizeof(game)); /* init all vars */
	game->mlx = mlx_init(); /* mlx init */
	game->wido = mlx_new_window(game->mlx, 1080, 720, "Midland v0.01"); /* create  the window */
	game->cubdat = cubdat; /* save de adress of the parser struct */
	game->keys = keys;	/* save the adres for keys structure */
	game->map = cubdat->map; /* get the map */
	game->p_x = cubdat->p_pos_x * 16; /* player start position x */
	game->p_y = cubdat->p_pos_y * 16; /* player start position x */
	import_map_sources(game); /* init and print map */
	game->background = mlx_new_image(game->mlx, 1080, 720);
	game->bkgrn_data = mlx_get_data_addr(game->background, &game->bpp, &game->l_size, &game->endian);
	draw_sky_floor(game);

}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wido); /* destroy window */
	exit(0);
}
