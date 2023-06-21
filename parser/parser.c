/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:02:22 by marvin            #+#    #+#             */
/*   Updated: 2023/06/21 16:46:07 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* Raw data printer
*/
//static void	data_printer(t_mapdata map_data)
//{
//	t_rgbcol	f_color;
//	t_rgbcol	c_color;
//
//	f_color = map_data.raw_data.f_col;
//	c_color = map_data.raw_data.c_col;
//	printf("################# DATA INTO PARSER #################\n");
//	printf("NO data from RAW_DATA --> %s\n", map_data.raw_data.no_route);
//	printf("EA data from RAW_DATA --> %s\n", map_data.raw_data.ea_route);
//	printf("WE data from RAW_DATA --> %s\n", map_data.raw_data.we_route);
//	printf("SO data from RAW_DATA --> %s\n", map_data.raw_data.so_route);
//	printf("[F] COLOR --> R: %d | G: %d | B: %d\n", f_color.r, f_color.g,
//		f_color.b);
//	printf("[C] COLOR --> R: %d | G: %d | B: %d\n", c_color.r, c_color.g,
//		c_color.b);
//	printf("####################################################\n");
//}

/* Free of data raw_map
*/
//static void	datafree(t_mapdata map_data)
//{
//	free(map_data.raw_data.no_route);
//	free(map_data.raw_data.ea_route);
//	free(map_data.raw_data.we_route);
//	free(map_data.raw_data.so_route);
//}

// Transform t_rgbcol to t_col struct
static t_col	rgbcol_to_col(t_rgbcol rgbcol)
{
	t_col	col;

	col.r = rgbcol.r;
	col.g = rgbcol.g;
	col.b = rgbcol.b;
	return (col);
}

// Transform t_mapdat to t_cubdat
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
	cubdat.f_col = rgbcol_to_col(mapdata->raw_data.f_col);
	cubdat.c_col = rgbcol_to_col(mapdata->raw_data.c_col);
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
	map_data.filename = cub_file;
	fd_map = open_file_and_check_ext(cub_file, ".cub");
	read_file(fd_map, &map_data);
	close_file(fd_map);
	cubdat = mapdat_to_cubdat(&map_data);
	if (map_checker(cubdat.map, cubdat.p_pos_x, cubdat.p_pos_y) != 1)
		error_msg_exit("error: map_checker: map no compatible", 1);
	renormalize_map(cubdat.map, cubdat.map_width, cubdat.map_height);
	return (cubdat);
}
