/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_assigner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:17:25 by marvin            #+#    #+#             */
/*   Updated: 2023/06/19 17:22:56 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* Assign data to their identifier. Data is passed by GNL_iterator. Return 1 if
	data was allocated. Return 0 if data is not allocated
*/
int	data_assigner(char *data, t_mapdata *map_data)
{
	char	**split_data;

	split_data = ft_split(data, ' ');
	if (check_identifier(split_data[0]) == 1 && split_data[1] != NULL)
	{
		assigner(split_data[0], split_data[1], map_data);
		//freedom(split_data);
		return (1);
	}
	freedom(split_data);
	return (0);
}

/* Find identifier and put the data into
*/
void	assigner(char *identifier, char *data, t_mapdata *map_data)
{
	if (ft_strncmp(identifier, "NO", 2) == 0 && data != NULL)
		rute_asign(&map_data->raw_data.no_route, data, &map_data->dac.no_rut);
	else if (ft_strncmp(identifier, "EA", 2) == 0 && data != NULL)
		rute_asign(&map_data->raw_data.ea_route, data, &map_data->dac.ea_rut);
	else if (ft_strncmp(identifier, "WE", 2) == 0 && data != NULL)
		rute_asign(&map_data->raw_data.we_route, data, &map_data->dac.we_rut);
	else if (ft_strncmp(identifier, "SO", 2) == 0 && data != NULL)
		rute_asign(&map_data->raw_data.so_route, data, &map_data->dac.so_rut);
	else if (ft_strncmp(identifier, "F", 1) == 0 && data != NULL)
		col_asign(&map_data->raw_data.f_col, data, &map_data->dac.f_col);
	else if (ft_strncmp(identifier, "C", 1) == 0 && data != NULL)
		col_asign(&map_data->raw_data.c_col, data, &map_data->dac.c_col);
}

/* Assign route data to their id in raw_map struct. Program is exited if data
	was allocated before
*/
void	rute_asign(char **rawmap_id, char *data, int *id_dac)
{
	if (*id_dac == 0)
	{
		*rawmap_id = malloc(ft_strlen(data) * sizeof(char *));
		ft_strlcpy(*rawmap_id, data, ft_strlen(data));
		*id_dac = 1;
	}
	else if (*id_dac == 1)
		errmsg_two_ids("SPRITE");
}

/* Split color data and assign it to their identifier
*/
void	col_asign(t_rgbcol *col, char *data, int *id_dac)
{
	char	**split_data;

	split_data = ft_split(data, ',');
	free(data);
	if (*id_dac == 0)
	{
		col->r = check_color(split_data[0]);
		col->g = check_color(split_data[1]);
		col->b = check_color(split_data[2]);
		*id_dac = 1;
	}
	else if (*id_dac == 1)
		errmsg_two_ids("COLOR");
	freedom(split_data);
}
