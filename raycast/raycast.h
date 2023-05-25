/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:31:37 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/26 01:08:10 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

#include "../cub3d.h"

typedef struct game {
	void	*mlx;
	void	*wido;
	void	*t_north;
	void	*t_east;
	void	*t_west;
	void	*t_south;
	int		t_size;
}	t_game;


int		exit_game(t_game *game);
void	minimap_init(t_game *game);

# endif
