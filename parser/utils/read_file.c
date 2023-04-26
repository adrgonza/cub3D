/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:22:36 by marvin            #+#    #+#             */
/*   Updated: 2023/03/05 23:22:36 by marvin           ###   ########.fr       */
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
	init_checker_dac(map_data);
	while (data_line /*&& c < 1*/)
	{
		//printf("FILE READER\n");
		data_line = get_next_line(file_fd);
		//printf("check_line int --> %d\n", check_read_line(data_line));
		//printf("Line %d is --> %s \n",c, data_line);
		if (data_line != NULL)
		{
			if (check_read_line(data_line) == 1)
				printf("line compatible with map\n");
			else if (data_assigner(data_line, map_data) == 0)
				printf("[Read_file] Line --> %s\n", data_line);
		}		
		//printf("------------------------------\n");
		free(data_line);
		c++;
	}
	// data_line = get_next_line(file_fd);
	// printf("Line --> %s", data_line);
	// data_assigner(data_line, map_data);
	(void)map_data;
}
