/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:31:37 by adrgonza          #+#    #+#             */
/*   Updated: 2023/06/20 03:46:05 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "../cub3d.h"
# include <math.h>
# include <float.h>

# define PI	3.1415926535

typedef struct s_cubdat	t_cubdat;

typedef struct rays {
	int		cord;
	int		column;
	int		*img_data;
	int		color;
	float	radian;
	float	angle;
	double	distance;
	float	p_x;
	float	p_y;
	float	delta_x;
	float	delta_y;
}	t_rays;

typedef struct keys {
	int	w;
	int	a;
	int	s;
	int	d;
	int	right;
	int	left;
}	t_keys;

typedef struct game {
	t_cubdat		*cubdat;
	t_keys			*keys;
	t_rays			*rays;
	void			*mlx;
	void			*window;
	void			*txt[4];
	int				*txt_data[4];
	void			*t_plyr;
	void			*t_floor;
	void			*t_wall;
	void			*t_south;
	void			*img;
	char			*img_data;
	int				img_bpp;
	int				img_size;
	int				img_end;
	int				**map;
	float			p_x;
	float			p_y;
	float			p_angle;
	int				map_posx;
	int				map_posy;
	int				prevmouse_x;
}	t_game;

int		exit_game(t_game *game);
void	print_minimap(t_game *game);
void	import_map_sources(t_game *game);
int		check_map(t_game *game, float y, float x);
void	draw_line(t_game *game);
void	draw_square(t_game *game);
int		key_released(int key, t_game *game);
int		key_press(int key, t_game *game);
int		key_actions(t_game *game);
void	draw_rays(t_game *game);
void	draw_sky_floor(t_game *game);
void	init_data(t_game *game, t_cubdat *cubdat, t_keys *keys);

#endif
