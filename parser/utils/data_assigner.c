/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_assigner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:17:25 by marvin            #+#    #+#             */
/*   Updated: 2023/06/21 13:16:15 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* Assign data to their identifier. Data is passed by GNL_iterator. Return 1 if
	data was allocated. Return 0 if data is not allocated
*/
int	data_assigner(char *data, t_mapdata *map_data)
{
	char	**split_data;
	int		i;

	i = -1;
	split_data = ft_split(data, ' ');
	if (check_id(split_data[0]) == 1)
	{
		printf("%s-->\n", split_data[0]);
		if (split_data[1])
			assigner(split_data[0], split_data[1], map_data);
		else
			error_msg_exit("error: data_assigner: bad id", 1);
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
		if (ends_with(data, ".xpm\n") != 0)
			error_msg_exit("error: sprite: bad sprite extension", 1);
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
	int		i;

	i = 0;
	split_data = ft_split(data, ',');
	while (split_data && split_data[i])
		i++;
	free(data);
	if (i != 3)
		error_msg_exit("error: color: more value arguments", 1);
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
