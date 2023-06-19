/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:27:28 by marvin            #+#    #+#             */
/*   Updated: 2023/06/16 09:48:34 by marvin           ###   ########.fr       */
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
	//free_map(map);
	(void)map;
	exit (1);
}
