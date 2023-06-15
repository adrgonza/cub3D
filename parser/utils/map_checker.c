/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:00:06 by marvin            #+#    #+#             */
/*   Updated: 2023/06/15 18:21:21 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// Checks if player is into walls. Return 1 if is true. 
// Fill the original map with 200
int		map_checker(int **map, int player_px, int player_py)
{
	int	**map_cpy;
	int	res;

	map_cpy = map;
	if (map_cpy[player_py][player_px] != 0)
	{
		if (map_cpy[player_py][player_px] == 1)
			return (1);
		else
			return (-1);
	}
	map_cpy[player_py][player_px] = 5000;
	res = 1;
	res *= map_checker(map_cpy, player_px + 1, player_py);
	res *= map_checker(map_cpy, player_px - 1, player_py);
	res *= map_checker(map_cpy, player_px, player_py + 1);
	res *= map_checker(map_cpy, player_px, player_py - 1);
	if (res == -1)
		return (-1);
	return (res);
}

// Revert the changues of map_checker on map
void	renormalize_map(int **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width - 1)
		{
			if ((map[i][j]) == 5000)
				map[i][j] = 0;
			j++;
		}
		i++;
	}
}
