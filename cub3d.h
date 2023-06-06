/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:55:14 by mcordoba          #+#    #+#             */
/*   Updated: 2023/06/06 17:54:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parser/parser.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "libs/libft/libft.h"
# include "libs/key_macos.h"

// Color struct
typedef struct s_col
{
	int	r;
	int	g;
	int	b;
}				t_col;

// Main data struct for raycaster
typedef struct s_cubdat
{
	char		*no_route;
	char		*so_route;
	char		*we_route;
	char		*ea_route;
	char		play_orient;
	int			p_pos_x;
	int			p_pos_y;
	t_col		f_col;
	t_col		c_col;
	int			map_height;
	int			map_width;
	int			**map;
}				t_cubdat;

///////////////////////////////////////////
//	errmanag.c
///////////////////////////////////////////
int		errmanag(int argc, char *argv[]);
int		check_file_ext(char *file, char *ext);

///////////////////////////////////////////
//	error_messages.c
///////////////////////////////////////////
void	error_msg_exit(char *err_msg, int exit_code);
void	error_no_player(int **map);

///////////////////////////////////////////
//	file_manager.c
///////////////////////////////////////////
int		open_file_and_check_ext(char *file, char *ext);
void	close_file(int file_fd);

///////////////////////////////////////////
//	file_manager.c
///////////////////////////////////////////
void	freedom(char **matrix);
void	double_freedom(char **matrix, char *line);
void	free_map(int **map);

#endif