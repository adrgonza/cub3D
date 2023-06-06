/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:00:06 by marvin            #+#    #+#             */
/*   Updated: 2023/06/06 22:58:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// Checks if player is into walls. Return 1 if is true
int	map_checker(int **map, int player_px, int player_py)
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
	map_cpy[player_py][player_px] = 1;
	res = 1;
	res *= map_checker(map_cpy, player_px + 1, player_py);
	res *= map_checker(map_cpy, player_px - 1, player_py);
	res *= map_checker(map_cpy, player_px, player_py + 1);
	res *= map_checker(map_cpy, player_px, player_py - 1);
	if (res == -1)
		return (-1);
	return (res);
}
