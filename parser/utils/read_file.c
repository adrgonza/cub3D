/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:22:36 by marvin            #+#    #+#             */
/*   Updated: 2023/06/21 17:35:22 by mcordoba         ###   ########.fr       */
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
	int		nb_ids;

	nb_ids = 0;
	map_data->fmap.height = 0;
	data_line = "a";
	init_checker_dac(map_data);
	while (data_line)
	{
		data_line = get_next_line(file_fd);
		if (data_line != NULL)
		{
			if (check_id(data_line) == 0 && mapl_compat(data_line) == 0
				&& ft_strncmp(data_line, "\n", 1) != 0)
				err_free_exit_msg(data_line, "error: bad data on .cub", 1);
			if (data_assigner(data_line, map_data) == 1)
				nb_ids++;
		}
		if (mapl_compat(data_line) == 1 && nb_ids != 6)
			err_free_exit_msg(data_line, "error: map before or ID lost", 1);
		free(data_line);
	}
	map_data->fmap = find_map(map_data->filename);
	save_map(map_data);
}
