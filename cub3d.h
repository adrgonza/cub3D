/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:55:14 by mcordoba          #+#    #+#             */
/*   Updated: 2023/05/26 01:09:52 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parser/parser.h"
# include "raycast/raycast.h"

# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "libs/libft/libft.h"
# include "libs/key_macos.h"

typedef struct s_rgbcol t_rgbcol;

typedef struct s_cubdat
{
	char		*no_route;
	char		*so_route;
	char		*we_route;
	char		*ea_route;
	char		play_orient;
	int			p_pos_x;
	int			p_pos_y;
	t_rgbcol	*f_col;
	t_rgbcol	*c_col;
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

///////////////////////////////////////////
//	raycast.c
///////////////////////////////////////////
void	raycast(t_cubdat *cubdat);

#endif
