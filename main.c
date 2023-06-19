/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:00:46 by mcordoba          #+#    #+#             */
/*   Updated: 2023/06/19 02:03:48 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Print all data of cubdat
void	leaks()
{
	system("leaks -q cub3D");
}

static void	print_cubdata_values(t_cubdat cubdat)
{
	int	h;
	int	w;

	h = 0;
	printf("################# DATA INTO MAAAIN #################\n");
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
	printf("NO data from RAW_DATA --> %s\n", cubdat.no_route);
	printf("EA data from RAW_DATA --> %s\n", cubdat.ea_route);
	printf("WE data from RAW_DATA --> %s\n", cubdat.we_route);
	printf("SO data from RAW_DATA --> %s\n", cubdat.so_route);
	printf("[F] COLOR --> R: %d | G: %d | B: %d\n", cubdat.f_col.r, cubdat.f_col.g,
		cubdat.f_col.b);
	printf("[C] COLOR --> R: %d | G: %d | B: %d\n", cubdat.c_col.r, cubdat.c_col.g,
		cubdat.c_col.b);
	printf("###################################################\n");
}

int	main(int argc, char *argv[])
{
	//atexit(leaks);
	t_cubdat	cubdat;

	printf("\t\033[0;35m----> Cub3d <----\033[0m\n");
	if (errmanag(argc, argv))
	{
		cubdat = parser(argv[1]);
		print_cubdata_values(cubdat);
		//leaks();
		raycast(&cubdat);
	}
	//system("leaks cub3d");
	printf("\033[0;35m      ----> Cub3d END <----\033[0m\n");
	(void)argc;
	(void)argv;
	return (0);
}
