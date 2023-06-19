/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:03:50 by marvin            #+#    #+#             */
/*   Updated: 2023/06/15 17:54:43 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// Copy map into other int **map_cpy
void	map_copyer(int **map, int ***map_cpy, int height, int width)
{
	int	i;
	int	j;
	int	nb_cpy;

	i = 0;
	nb_cpy = 0;
	map_cpy = malloc(height * sizeof(int *));
	if (!map_cpy)
		error_msg_exit("error: map_copyer: error in memory", 1);
	while (i < height)
	{
		map_cpy[i] = malloc(width * sizeof(int));
		if (!map_cpy[i])
			error_msg_exit("error: map_copyer: error in memory", 1);
		i++;
	}
	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			nb_cpy = map[i][j];
			*(map_cpy[i][j]) = nb_cpy;
			j++;
		}
		i++;
	}
}

// Return 1 if char exist in a set of chars. Return 0 if not
int	ft_hasany(char c, char *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// Convert char to int
int	char_to_int(char c)
{
	return (c - '0');
}
