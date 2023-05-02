/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:15:48 by marvin            #+#    #+#             */
/*   Updated: 2023/05/02 14:50:11 by marvin           ###   ########.fr       */
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
int	transform_to_map(char c, t_mapdata *map_data)
{
	if (ft_isdigit(c) == 1)
		return (c - '0');
	else if (c == ' ')
		return (2);
	else if ((c == 'N' || c == 'W' || c == 'E' || c == 'S')
		&& map_data->dac.play_or == 0)
	{
		map_data->raw_data.play_orient = c;
		map_data->dac.play_or = 1;
		return (3);
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

	j = 0;
	while (j < map_data->fmap.width - 1)
	{
		//printf("point --> %d\n", smu->map_line[j] - '0');
		map_data->map[smu->i][j] = transform_to_map(smu->map_line[j], map_data);
		j++;
	}
}

// Save map into map_data_struct
void	save_map(t_mapdata *map_data)
{
	t_smu	smu;
	
	smu.i = 0;
	set_gnl_to_mapinit(map_data->filename, map_data->fmap.l_start, &smu);
	map_data->map = malloc(map_data->fmap.height * sizeof(int *));
	if (!map_data->map)
		error_msg_exit("error: save_map: cannot allocate memory map", 1);
	while (smu.i < map_data->fmap.height)
	{
		map_data->map[smu.i] = malloc(map_data->fmap.width * sizeof(int) - 1);
		if (!map_data->map[smu.i])
			error_msg_exit("error: save_map: cannot allocate memory map", 1);
		smu.map_line = get_next_line(smu.ffd);
		allocate_data_map(map_data, &smu);
		free(smu.map_line);
		smu.i++;
	}
	(void)map_data;
}
