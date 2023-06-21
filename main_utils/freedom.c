/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 00:08:19 by marvin            #+#    #+#             */
/*   Updated: 2023/06/21 16:26:52 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Freedom to double pointer /double array
*/
void	freedom(char **matrix)
{
	int	c;

	c = 0;
	while (matrix && matrix[c] != NULL)
	{
		free(matrix[c]);
		c++;
	}
	free(matrix);
}

void	double_freedom(char **matrix, char *line)
{
	freedom(matrix);
	free(line);
}

/* Liberate map memory*/
void	free_map(int **map)
{
	int	c;

	c = 0;
	while (map && map[c] != NULL)
	{
		free(map[c]);
		c++;
	}
	free(map);
}
