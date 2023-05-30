/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 01:00:09 by adrgonza          #+#    #+#             */
/*   Updated: 2023/05/30 18:23:07 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	draw_rays(t_game *game, t_rays *rays)
{
	rays->ra = game->p_angle;
	rays->r = -1;
	while (++rays->r < 1)
	{
		rays->dof = 0;
		rays->a_tan = -1 / tan(rays->ra);
		if (rays->ra > PI)
		{
			rays->ry = (((int) game->p_y >> 6) << 6) - 0.0001;
			rays->rx = (game->p_y - rays->ry) * rays->a_tan + game->p_x;
			rays->yo = -64;
			rays->xo = -rays->yo * rays->a_tan;
		}
		if (rays->ra < PI)
		{
			rays->ry = (((int) game->p_y >> 6) << 6) + 64;
			rays->rx = (game->p_y - rays->ry) * rays->a_tan + game->p_x;
			rays->yo = 64;
			rays->xo = -rays->yo * rays->a_tan;
		}
		if (rays->ra == 0 || rays->ra == PI)
		{
			rays->rx = game->p_x;
			rays->ry = game->p_y;
			rays->dof = 8;
		}
		while (rays->dof < 8)
		{
			rays->mx = (int)(rays->rx) >> 6;
			rays->my = (int)(rays->ry) >> 6;
			rays->mp = rays->my * game->map_posx + rays->mx;
			if (rays->mp < game->map_posx * game->map_posy)
				rays->dof = 8;
			else
			{
				rays->rx += rays->xo;
				rays->ry += rays->yo;
				rays->dof += 1;
			}
		}
		draw_line(game);
	}

}
