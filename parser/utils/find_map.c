/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:56:57 by marvin            #+#    #+#             */
/*   Updated: 2023/04/26 00:56:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// Check if the line contains a time of line compatible with a map
// If its true return(1) if not, return(0)
int	check_read_line(char *data_line)
{
	int	i;

	i = 0;
	if (!data_line)
		return (0);
	while (data_line[i])
	{
		if (!(data_line[i] == ' ' || data_line[i] == '0' || data_line[i] == '1'
			|| data_line[i] == 'S' || data_line[i] == 'E' || data_line[i] == 'W'
			|| data_line[i] == 'N'))
			return (0);
		i++;
	}
	return (1);
}

// Find map. Return a struct with init map, end map (nb_line) and height
//t_fmap	find_map(int nb_line, int file_fd)
//{
//
//}
