/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:15:48 by marvin            #+#    #+#             */
/*   Updated: 2023/05/02 12:48:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// Set the gnl to the init line of map.
void	set_gnl_to_mapinit(char *filename, int init_line, t_smu *smu)
{
	smu->i = 0;
	smu->ffd = open_file_and_check_ext(filename, ".cub");
	while (smu->i < init_line)
	{
		free(get_next_line(smu->ffd));
		smu->i++;
	}
}

// Save map into map_data_struct
void	save_map(t_mapdata *map_data)
{
	t_smu	smu;
	
	set_gnl_to_mapinit(map_data->filename, map_data->fmap.l_start, &smu);
	printf("SMap F_LINE --> %s\n", get_next_line(smu.ffd));
	(void)map_data;
}
