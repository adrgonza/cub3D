/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:44:18 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/09 15:19:36 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	init_data(t_game *game, t_cubdat *cubdat, t_keys *keys)
{
	int	i;
	int y;
	int	x;
	int	tex_width, tex_height;

	ft_bzero(game, sizeof(*game)); /* init all vars */
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
	game->textures[0] = mlx_xpm_file_to_image(game->mlx, "test_maps/textures/test/north.xpm", &tex_width, &tex_height);
	game->textures[1] = mlx_xpm_file_to_image(game->mlx, "test_maps/textures/test/east.xpm", &tex_width, &tex_height);
	game->textures[2] = mlx_xpm_file_to_image(game->mlx, "test_maps/textures/test/south.xpm", &tex_width, &tex_height);
	game->textures[3] = mlx_xpm_file_to_image(game->mlx, "test_maps/textures/test/west.xpm", &tex_width, &tex_height);
	i = -1;
	while (++i < 4)
		game->texture_data[i] = (int *)mlx_get_data_addr(game->textures[i], &game->bpp, &game->l_size, &game->endian);
	i = - 1;
	while (++i < 4)
	{
		game->new_tex[i] = mlx_new_image(game->mlx, 64, 64);
		if (game->new_tex[i] == NULL)
		{
			printf("Failed to create new texture for index %d\n", i);
		}
		game->new_text_data[i] = (int *)mlx_get_data_addr(game->new_tex[i], &game->bpp, &game->l_size, &game->endian);
		if (game->new_text_data[i] == NULL)
		{
			printf("Failed to get data address for new texture for index %d\n", i);
		}
		y = -1;
		while (++y < 64)
		{
			x = -1;
			while (++x < 64)
			{
				if (y < 32)
					game->new_text_data[i][y * 64 + x] = game->texture_data[i][y * 64 + x];
				else
					game->new_text_data[i][y * 64 + x] = game->texture_data[i][y * 64 + x];
			}
		}
	}
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wido); /* destroy window */
	exit(0);
}


/*void *tex0 = mlx_xpm_file_to_image(game->mlx, "texture0.xpm", &tex_width, &tex_height);
void *tex1 = mlx_xpm_file_to_image(game->mlx, "texture1.xpm", &tex_width, &tex_height);

// Crear una nueva imagen de 64x64
void *new_tex = mlx_new_image(game->mlx, 64, 64);
int *new_tex_data = (int *)mlx_get_data_addr(new_tex, &game->bpp, &game->l_size, &game->endian);

// Obtener los datos de las texturas
int *tex0_data = (int *)mlx_get_data_addr(tex0, &game->bpp, &game->l_size, &game->endian);
int *tex1_data = (int *)mlx_get_data_addr(tex1, &game->bpp, &game->l_size, &game->endian);

// Combinar las dos texturas en la nueva imagen
for (int y = 0; y < 64; y++)
{
    for (int x = 0; x < 64; x++)
    {
        if (y < 32)
            new_tex_data[y * 64 + x] = tex0_data[y * 64 + x];
        else
            new_tex_data[y * 64 + x] = tex1_data[y * 64 + x];
    }
}

// Ahora puedes usar new_tex como tu textura combinada
game->textures[0] = new_tex*/
