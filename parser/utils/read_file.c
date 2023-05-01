/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:22:36 by marvin            #+#    #+#             */
/*   Updated: 2023/04/26 19:36:36 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"


void	read_file(int file_fd, t_mapdata *map_data)
{
	char	*data_line;
	int		c;

	c = 0;
	map_data->fmap.height = 0;
	//printf("------------------------------\n");
	data_line = "a";
	init_checker_dac(map_data);
	while (data_line /*&& c < 1*/)
	{
		//printf("FILE READER\n");
		data_line = get_next_line(file_fd);
		//printf("check_line int --> %d\n", check_read_line(data_line));
		//printf("Line %d is --> %s \n",c, data_line);
		if (data_line != NULL)
			data_assigner(data_line, map_data);
		//printf("------------------------------\n");
		free(data_line);
		c++;
	}
	map_data->fmap = find_map(map_data->filename);
	printf("Map_height --> %d\n", map_data->fmap.height);
	printf("Map_width --> %d\n", map_data->fmap.width);
	printf("Map_l_start --> %d\n", map_data->fmap.l_start);
	// if (map_compatible_line("   111  0  00") == 1)
		// printf("dataline COMPATIBLE\n");
	// else
		// printf("dataline --> NO <-- COMPATIBLE\n");

	//printf("map_height --> %d\n", map_data->fmap.height);
	// data_line = get_next_line(file_fd);
	// printf("Line --> %s", data_line);
	// data_assigner(data_line, map_data);
}
