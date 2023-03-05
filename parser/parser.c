/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:02:22 by marvin            #+#    #+#             */
/*   Updated: 2023/03/05 20:02:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser(char *cub_file)
{
	t_mapdata	*map_data;
	int			fd_map;

	printf("Parser\n");
	close_file(2);
	fd_map = open_file_and_check_ext(cub_file, ".cub");
	printf("Map fd --> %d\n", fd_map);
	(void)map_data;
	(void)cub_file;
}
