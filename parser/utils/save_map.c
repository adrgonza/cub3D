/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:15:48 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 23:16:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// Set the gnl to the init line of map.
void	set_gnl_to_mapinit(char *filename, int init_line, t_smu *smu)
{
	int	i;
	
	i = 0;
	smu->map_line = NULL;
	smu->ffd = open_file_and_check_ext(filename, ".cub");
	while (i < init_line)
	{
		free(get_next_line(smu->ffd));
		i++;
	}
}

// Transform the char to the correct value for map**
// If is digit, return the number 0 or 1
// If char is ' ', return 2
// If char is player, return 3 & set orientation in raw_data (play_orient)
// Program exited id exist duplicated player identifiers
int	transform_to_map(char c, int char_pos, t_mapdata *map_data, t_smu *smu)
{
	if (ft_isdigit(c) == 1)
		return (c - '0');
	else if (c == ' ' || c == '\0' || c == '\n')
		return (-1);
	else if ((c == 'N' || c == 'W' || c == 'E' || c == 'S')
		&& map_data->dac.play_or == 0)
	{
		map_data->raw_data.play_orient = c;
		map_data->raw_data.p_pos_x = char_pos;
		map_data->raw_data.p_pos_y = smu->i;
		map_data->dac.play_or = 1;
		return (0);
	}
	else if ((c == 'N' || c == 'W' || c == 'E' || c == 'S')
		&& map_data->dac.play_or == 1)
		error_msg_exit("error: map player: more than one identifier", 1);
	return (0);
}

// Alocate data in every point of map**
void	allocate_data_map(t_mapdata *map_data, t_smu *smu)
{
	int		j;
	int		data_transform;
	int		width;
	int		find_lb;

	j = 0;
	find_lb = 0;
	width = map_data->fmap.width;
	if (smu->map_line == NULL)
		return ;
	while (j < width - 1)
	{
		if (find_lb == 0)
		{
			if (smu->map_line[j] == '\n' || smu->map_line[j] == '\0')
				find_lb++;
			//printf("point --> %d\n", smu->map_line[j] - '0');
			data_transform = transform_to_map(smu->map_line[j], j, map_data, smu);
			map_data->raw_data.map[smu->i][j] = data_transform;
		}
		else if (find_lb != 0)
		{
			data_transform = transform_to_map('\0', j, map_data, smu);
			map_data->raw_data.map[smu->i][j] = data_transform;
		}
		j++;
	}
}

// Save map into map_data_struct
void	save_map(t_mapdata *map_data)
{
	t_smu	smu;
	
	smu.i = 0;
	set_gnl_to_mapinit(map_data->filename, map_data->fmap.l_start, &smu);
	map_data->raw_data.map = malloc(map_data->fmap.height * sizeof(int *));
	if (!map_data->raw_data.map)
		error_msg_exit("error: save_map: cannot allocate memory map", 1);
	while (smu.i < map_data->fmap.height)
	{
		map_data->raw_data.map[smu.i] = malloc(map_data->fmap.width
			* sizeof(int) - 1);
		if (!map_data->raw_data.map[smu.i])
			error_msg_exit("error: save_map: cannot allocate memory map", 1);
		smu.map_line = get_next_line(smu.ffd);
		if (!smu.map_line || smu.map_line == NULL)
			return (free(smu.map_line));
		allocate_data_map(map_data, &smu);
		free(smu.map_line);
		smu.i++;
	}
	if (map_data->dac.play_or == 0)
		error_no_player(map_data->raw_data.map);
	close(smu.ffd);
}
