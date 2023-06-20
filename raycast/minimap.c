/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:36:36 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/20 03:49:27 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

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

void	print_minimap2(t_game *g, int i, int **map)
{
	int	j;

	j = -1;
	while (++j < g->cubdat->map_width)
	{
		if (j < 0 || j > g->cubdat->map_width - 2 || i < 0 || i > g->cubdat->map_height - 1)
			mlx_put_image_to_window(g->mlx, g->window, g->t_wall, g->map_posy, g->map_posx);
		else if (map[i][j] >= 1)
			mlx_put_image_to_window(g->mlx, g->window, g->t_wall, g->map_posy, g->map_posx);
		else if (map[i][j] == -1)
			mlx_put_image_to_window(g->mlx, g->window, g->t_south, g->map_posy, g->map_posx);
		else if (map[i][j] == 0)
			mlx_put_image_to_window(g->mlx, g->window, g->t_floor, g->map_posy, g->map_posx);
		g->map_posy += 16;
	}
}

void	print_minimap(t_game *g)
{
	int	**map;
	int	i;

	g->map_posx = 0;
	map = g->map;
	i = -1;
	while (++i < g->cubdat->map_height)
	{
		g->map_posy = 0;
		print_minimap2(g, i, map);
		g->map_posx += 16;
	}
	draw_square(g);
	draw_line(g);
}
