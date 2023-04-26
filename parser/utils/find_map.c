/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:56:57 by marvin            #+#    #+#             */
/*   Updated: 2023/04/26 19:47:19 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int ft_hasany(char c, char *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while(set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// Check if the line contains a time of line compatible with a map
// If its true return(1) if not, return(0)
int	map_compatible_line(char *data_line)
{
	int	i;

	i = 0;
	if (!data_line)
		return (0);
	while (data_line[i])
	{
		/*if (data_line[i] != ' ' && data_line[i] != '1' && data_line[i] != '0'
			&& data_line[i] != 'S' && data_line[i] != 'E' && data_line[i] != 'W'
			&& data_line[i] != 'N' && data_line[i] != '\n')*/
		if (!ft_hasany(data_line[i], " 10SEWN\n"))
			return (0);
		i++;
	}
	return (1);
}

// Find map. Return a struct with init map, end map (nb_line) and height
t_fmap	find_map(char *filename)
{
	t_fmap	f_map;
	int		i;
	int		ffd;
	char	*data_line;

	f_map.height = 0;
	i = 0;
	ffd = open_file_and_check_ext(filename, ".cub");
	data_line = "a";
	while (data_line)
	{
		data_line = get_next_line(ffd);
		//printf("FIND_MAP dataline --> %s\n", data_line);
		if (map_compatible_line(data_line) == 1)
			printf("FIND_MAP dataline COMPATIBLE --> %s\n", data_line);
		free(data_line);
		i++;
	}

	return (f_map);
}
