/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmanag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:07:11 by marvin            #+#    #+#             */
/*   Updated: 2023/05/25 18:19:38 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	If errmanag pass, return 1, else 0
*/
int	errmanag(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Please, insert a valid map: 'map.cub'\n");
		exit (0);
	}
	printf("Route: %s\n", argv[1]);
	check_file_ext(argv[1], ".cub");
	return (1);
}

/*
	Check file extension
*/
int	check_file_ext(char *route, char *ext)
{
	int	route_len;
	int	ext_len;

	route_len = (int)ft_strlen(route) - 1;
	ext_len = (int)ft_strlen(ext) - 1;
	while (ext_len > 0)
	{
		if (route[route_len - 1] != ext[ext_len - 1])
		{
			printf("Map error, bust be: .cub\n");
			exit (0);
		}
		ext_len--;
		route_len--;
	}
	return (1);
}
