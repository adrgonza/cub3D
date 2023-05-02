/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:22:36 by marvin            #+#    #+#             */
/*   Updated: 2023/05/02 14:38:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// Print the int **map values
void	print_map_values(t_mapdata *map_data)
{
	int	h;
	int	w;

	h = 0;
	printf("-->      MAP SAVED      <--\n");
	printf("\tPLAY ORIENT --> %c <--\n", map_data->raw_data.play_orient);
	while (h < map_data->fmap.height)
	{
		w = 0;
		while (w < map_data->fmap.width - 1)
		{
			printf("%d", map_data->map[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
	printf("-->    MAP SAVED END    <--\n");
}

// This function read the file and save the data into the map_data struct
void	read_file(int file_fd, t_mapdata *map_data)
{
	char	*data_line;
	int		c;

	c = 0;
	map_data->fmap.height = 0;
	data_line = "a";
	init_checker_dac(map_data);
	while (data_line)
	{
		data_line = get_next_line(file_fd);
		if (data_line != NULL)
			data_assigner(data_line, map_data);
		free(data_line);
		c++;
	}
	map_data->fmap = find_map(map_data->filename);
	printf("Map_height --> %d\n", map_data->fmap.height);
	printf("Map_width --> %d\n", map_data->fmap.width);
	printf("Map_l_start --> %d\n", map_data->fmap.l_start);
	save_map(map_data);
	print_map_values(map_data);
	// if (map_compatible_line("   111  0  00") == 1)
		// printf("dataline COMPATIBLE\n");
	// else
		// printf("dataline --> NO <-- COMPATIBLE\n");

	//printf("map_height --> %d\n", map_data->fmap.height);
	// data_line = get_next_line(file_fd);
	// printf("Line --> %s", data_line);
	// data_assigner(data_line, map_data);
}
