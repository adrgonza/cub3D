/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:31:37 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/02 01:02:48 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "../cub3d.h"
# include <math.h>

#define PI 3.1415926535

typedef struct s_cubdat t_cubdat;

typedef struct keys {
	int	w;
	int a;
	int s;
	int d;
	int right;
	int left;
}	t_keys;

typedef struct game {
	t_cubdat	*cubdat;
	t_keys		*keys;
	void		*mlx;
	void		*wido;
	void		*t_plyr;
	void		*t_floor;
	void		*t_wall;
	void		*t_south;
	void		*background;
	int			**map;
	float		p_x;
	float		p_y;
	float		p_dx; //delta x
	float		p_dy; //delta y
	float		p_angle;
	int			map_posx;
	int			map_posy;
}	t_game;

int		exit_game(t_game *game);
void	minimap_init(t_game *game);
void	print_minimap(t_game *game);
int		check_map(t_game *game, float y, float x);
void	draw_line(t_game *game);
void	draw_square(t_game *game);
int		key_released(int key, t_game *game);
int		key_press(int key, t_game *game);
int		key_actions(t_game *game);
void	draw_rays(t_game *game);
void	draw_sky_floor(t_game *game);
void	init_data(t_game *game, t_cubdat *cubdat, t_keys *keys);

# endif
