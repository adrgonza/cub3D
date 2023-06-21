/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:27:28 by marvin            #+#    #+#             */
/*   Updated: 2023/06/21 15:40:09 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Prints error message and exit with code*/
void	error_msg_exit(char *err_msg, int exit_code)
{
	printf("%s\n", err_msg);
	exit (exit_code);
}

void	error_no_player(int **map)
{
	printf("%s\n", "error: map: no player identifier");
	(void)map;
	exit (1);
}
