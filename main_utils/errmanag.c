/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmanag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:07:11 by marvin            #+#    #+#             */
/*   Updated: 2023/06/21 15:42:46 by mcordoba         ###   ########.fr       */
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
	printf("Map opened: %s\n", argv[1]);
	check_file_ext(argv[1], ".cub");
	return (1);
}

/*
	Check file extension
	Return 1 if its correct
	0 if its bad
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

// Chechs if a string ends with another string (♥️ @dangonza)
// Returns 0 if true, different value otherwise
int	ends_with(char *str, char *end)
{
	size_t	str_length;
	size_t	end_length;

	if (!str || !end)
		return (1);
	str_length = ft_strlen(str);
	end_length = ft_strlen(end);
	if (end_length > str_length)
		return (1);
	return (ft_strncmp(str + (str_length - end_length), end, end_length));
}

/*
	Check file texture extension
	Return 1 if its correct
	0 if its bad
*/
int	check_texture_ext(char *route, char *ext)
{
	int	route_len;
	int	ext_len;

	route_len = (int)ft_strlen(route) - 1;
	ext_len = (int)ft_strlen(ext) - 1;
	while (ext_len > 0)
	{
		if (route[route_len - 1] != ext[ext_len - 1])
			error_msg_exit("error: sprite: bad sprite extension", 1);
		ext_len--;
		route_len--;
	}
	return (1);
}
