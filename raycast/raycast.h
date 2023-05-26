/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:31:37 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/26 18:30:51 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

#include "../cub3d.h"

typedef struct s_cubdat t_cubdat;

typedef struct game {
	void		*mlx;
	void		*wido;
	void		*t_plyr;
	void		*t_floor;
	void		*t_wall;
	void		*t_south;
	t_cubdat	*cubdat;
	int			**map;
	float		plyr_x;
	float		plyr_y;
	int			map_posx;
	int			map_posy;
	int			t_size;
}	t_game;

typedef struct raycast {
	double	p_posx;
	double	p_posy;
	double	p_dirx;
	double	p_diry;
	double	p_planex;
	double	p_planey;
	double	time;
	double	old_time;
}	t_raycast;

int		exit_game(t_game *game);
void	minimap_init(t_game *game);
void	print_minimap(t_game *game);
int		check_map(t_game *game, int y, int x);

# endif
