/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:02:22 by marvin            #+#    #+#             */
/*   Updated: 2023/05/29 20:44:47 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Raw data printer
*/
static void	data_printer(t_mapdata map_data)
{
	t_rgbcol	f_color;
	t_rgbcol	c_color;

	f_color = map_data.raw_data.f_col;
	c_color = map_data.raw_data.c_col;
	printf("################# DATA INTO PARSER #################\n");
	printf("NO data from RAW_DATA --> %s\n", map_data.raw_data.no_route);
	printf("EA data from RAW_DATA --> %s\n", map_data.raw_data.ea_route);
	printf("WE data from RAW_DATA --> %s\n", map_data.raw_data.we_route);
	printf("SO data from RAW_DATA --> %s\n", map_data.raw_data.so_route);
	printf("[F] COLOR --> R: %d | G: %d | B: %d\n", f_color.r, f_color.g,
		f_color.b);
	printf("[C] COLOR --> R: %d | G: %d | B: %d\n", c_color.r, c_color.g,
		c_color.b);
	printf("####################################################\n");
}

/* Free of data raw_map
*/
static void	datafree(t_mapdata map_data)
{
	free(map_data.raw_data.no_route);
	free(map_data.raw_data.ea_route);
	free(map_data.raw_data.we_route);
	free(map_data.raw_data.so_route);
}

t_cubdat	mapdat_to_cubdat(t_mapdata *mapdata)
{
	t_cubdat	cubdat;

	cubdat.no_route = mapdata->raw_data.no_route;
	cubdat.so_route = mapdata->raw_data.so_route;
	cubdat.we_route = mapdata->raw_data.we_route;
	cubdat.ea_route = mapdata->raw_data.ea_route;
	cubdat.play_orient = mapdata->raw_data.play_orient;
	cubdat.p_pos_x = mapdata->raw_data.p_pos_x;
	cubdat.p_pos_y = mapdata->raw_data.p_pos_y;
	cubdat.f_col.r = mapdata->raw_data.f_col.r;
	cubdat.f_col.g = mapdata->raw_data.f_col.g;
	cubdat.f_col.b = mapdata->raw_data.f_col.b;
	cubdat.c_col.r = mapdata->raw_data.c_col.r;
	cubdat.c_col.g = mapdata->raw_data.c_col.g;
	cubdat.c_col.b = mapdata->raw_data.c_col.b;
	cubdat.map_height = mapdata->fmap.height;
	cubdat.map_width = mapdata->fmap.width;
	cubdat.map = mapdata->raw_data.map;
	return (cubdat);
}

// Parse .cub file and return a t_cubdat
t_cubdat	parser(char *cub_file)
{
	t_mapdata	map_data;
	t_cubdat	cubdat;
	int			fd_map;

	map_data.init = 1;
	printf("Parser\n");
	map_data.filename = cub_file;
	fd_map = open_file_and_check_ext(cub_file, ".cub");
	read_file(fd_map, &map_data);
	data_printer(map_data);
	close_file(fd_map);
	cubdat = mapdat_to_cubdat(&map_data);
	//datafree(map_data);
	return (cubdat);
}
