/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:27:53 by marvin            #+#    #+#             */
/*   Updated: 2023/03/05 21:27:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	open_file_and_check_ext(char *file, char *ext)
{
	int fd;

	if (check_file_ext(file, ext) == 1)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			printf("Map %s cant be opened\n", file);
			exit (0);
		}
		return (fd);
	}
	printf("File %s is not a %s type\n", file, ext);
	exit (0);
	return (0);
}

void	close_file(int file_fd)
{
	close(file_fd);
}
