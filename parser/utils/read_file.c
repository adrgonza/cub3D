/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:22:36 by marvin            #+#    #+#             */
/*   Updated: 2023/06/20 18:50:03 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// Print the int **map values (t_mapdata *map_data)
void	print_map_values(t_mapdata *map_data)
{
	int	h;
	int	w;

	h = 0;
	printf("-->      MAP SAVED      <--\n");
	printf("\t\033[0;35mPLAY ORIENT --> %c <--\033[0m\n",
		map_data->raw_data.play_orient);
	while (h < map_data->fmap.height)
	{
		w = 0;
		while (w < map_data->fmap.width - 1)
		{
			printf("%d", map_data->raw_data.map[h][w]);
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
	int		last_idline;
	int		nb_ids;

	c = 0;
	nb_ids = 0;
	map_data->fmap.height = 0;
	data_line = "a";
	init_checker_dac(map_data);
	while (data_line)
	{
		data_line = get_next_line(file_fd);
		if (data_line != NULL)
		{
			if (check_identifier(data_line) == 0
				&& map_compatible_line(data_line) == 0
				&& ft_strncmp(data_line, "\n", 1) != 0)
				error_msg_exit("error: bad data on .cub", 1);
			if (data_assigner(data_line, map_data) == 1)
				nb_ids++;
		}
		if (map_compatible_line(data_line) == 1 && nb_ids != 6)
			error_msg_exit("error: read_file: map before or ID lost", 1);
		free(data_line);
		c++;
	}
	printf("\t\tlast_idline --> %d\n", nb_ids);

	map_data->fmap = find_map(map_data->filename);
	//printf("Map_height --> %d\n", map_data->fmap.height);
	//printf("Map_width --> %d\n", map_data->fmap.width);
	//printf("Map_l_start --> %d\n", map_data->fmap.l_start);
	save_map(map_data);
	//print_map_values(map_data);
	//printf("\033[0;35mPLAYER: POS_X --> %d POS_Y --> %d\033[0m\n",
	//	map_data->raw_data.p_pos_x, map_data->raw_data.p_pos_y);
	//map_checker(map_data);
	// if (map_compatible_line("   111  0  00") == 1)
		// printf("dataline COMPATIBLE\n");
	// else
		// printf("dataline --> NO <-- COMPATIBLE\n");

	//printf("map_height --> %d\n", map_data->fmap.height);
	// data_line = get_next_line(file_fd);
	// printf("Line --> %s", data_line);
	// data_assigner(data_line, map_data);
}
