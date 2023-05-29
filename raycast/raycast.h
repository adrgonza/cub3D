/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:31:37 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/29 19:55:54 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "../cub3d.h"
# include <math.h>

#define PI 3.1415926535

typedef struct s_cubdat t_cubdat;

typedef struct game {
	t_cubdat	*cubdat;
	void		*mlx;
	void		*wido;
	void		*t_plyr;
	void		*t_floor;
	void		*t_wall;
	void		*t_south;
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
int	print_minimap(void *data);
int		check_map(t_game *game, int y, int x);

# endif
