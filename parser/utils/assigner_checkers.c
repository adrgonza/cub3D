/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigner_checkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:18:52 by marvin            #+#    #+#             */
/*   Updated: 2023/05/02 14:47:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* Initialice t_dac checker struct
*/
void	init_checker_dac(t_mapdata *map_data)
{
	map_data->dac.no_rut = 0;
	map_data->dac.so_rut = 0;
	map_data->dac.we_rut = 0;
	map_data->dac.ea_rut = 0;
	map_data->dac.c_col = 0;
	map_data->dac.f_col = 0;
	map_data->dac.play_or = 0;
}

/* Check if identifier is equal. If its equal, return 1
*/
int	check_identifier(char *identifier)
{
	//printf("Identifier --> %s\n", identifier);
	if (ft_strncmp(identifier, "NO", 2) == 0
		|| ft_strncmp(identifier, "EA", 2) == 0
		|| ft_strncmp(identifier, "WE", 2) == 0
		|| ft_strncmp(identifier, "SO", 2) == 0
		|| ft_strncmp(identifier, "F", 1) == 0
		|| ft_strncmp(identifier, "C", 1) == 0)
	{
		return (1);
	}
	//printf("Bad sprite/color indentifier in map. Check it\n");
	return (0);
}

/* Check correct color values. Return color value.
	If color exceeds their correct range, return value will be rounded
	to limits.
	If color doesnt exist, return value will be 0
*/
int	check_color(char *color)
{
	int	c_value;

	if (color != NULL)
	{
		c_value = ft_atoi(color);
		if (c_value > 255)
			return (255);
		else if (c_value < 0)
			return (0);
		else
			return (c_value);
	}
	return (0);
}