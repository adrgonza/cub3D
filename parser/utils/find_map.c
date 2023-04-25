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
int	check_read_line(char *dataline)
{
	int	i;

	i = 0;
	if (!dataline)
		return (0);
	while (i < (int)ft_strlen(dataline))
	{
		if (dataline[i] == ' ' || dataline[i] == '0' || dataline[i] == '1'
			|| dataline[i] == 'S' || dataline[i] == 'E' || dataline[i] == 'W')
			i++;
		else
			return (0);
	}
	return (1);
}

// Find map. Return a struct with init map, end map (nb_line) and height
t_fmap	find_map(int nb_line)
{
	
}