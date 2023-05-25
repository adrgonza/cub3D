/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:00:46 by mcordoba          #+#    #+#             */
/*   Updated: 2023/05/26 01:05:38 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Print all data of cubdat
static void	print_cubdata_values(t_cubdat cubdat)
{
	int	h;
	int	w;

	h = 0;
	printf("-->      MAP SAVED      <--\n");
	printf("\t\033[0;35mPLAY ORIENT --> %c <--\033[0m\n",
		cubdat.play_orient);
	printf("\033[0;35mPLAYER: POS_X --> %d POS_Y --> %d\033[0m\n",
		cubdat.p_pos_x, cubdat.p_pos_y);
	while (h < cubdat.map_height)
	{
		w = 0;
		while (w < cubdat.map_width - 1)
		{
			printf("%d", cubdat.map[h][w]);
			w++;
		}
		printf("\n");
		h++;
	}
	printf("-->    MAP SAVED END    <--\n");
	printf("Map_height --> %d\n", cubdat.map_height);
	printf("Map_width --> %d\n", cubdat.map_width);
}

int	main(int argc, char *argv[])
{
	t_cubdat	cubdat;

	printf("\t\033[0;35m----> Cub3d <----\033[0m\n");
	if (errmanag(argc, argv))
	{
		cubdat = parser(argv[1]);
		print_cubdata_values(cubdat);
	}
	raycast(&cubdat);
	//system("leaks cub3d");
	printf("\033[0;35m      ----> Cub3d END <----\033[0m\n");
	(void)argc;
	(void)argv;
	return (0);
}
