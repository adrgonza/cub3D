/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:55:14 by mcordoba          #+#    #+#             */
/*   Updated: 2023/05/24 11:37:19 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parser/parser.h"
# include "raycast/raycast.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include "libs/libft/libft.h"
# include "libs/key_macos.h"

///////////////////////////////////////////
//	errmanag.c
///////////////////////////////////////////
void	errmanag(int argc, char *argv[]);
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

#endif
