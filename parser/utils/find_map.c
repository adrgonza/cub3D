/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:56:57 by marvin            #+#    #+#             */
/*   Updated: 2023/04/26 19:47:19 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

int ft_hasany(char c, char *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while(set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// Check if the line contains a time of line compatible with a map
// If data_line is "\n" return 0
// If its true return(1) if not, return(0)
int	map_compatible_line(char *data_line)
{
	int	i;

	i = 0;
	if (!data_line)
		return (0);
	if (ft_strncmp(data_line, "\n", (int)ft_strlen(data_line)) == 0)
		return (0);
	while (data_line[i])
	{
		if (!ft_hasany(data_line[i], " 10SEWN\n"))
			return (0);
		i++;
	}
	return (1);
}

// Compare size of the last line and current line. Return the max size of line
int	compare_line_size(int l_len, char *data_line)
{
	int	d_line_size;

	d_line_size = (int)ft_strlen(data_line);
	if (d_line_size > l_len)
		return (d_line_size);
	else
		return (l_len);
	return (0);
}

// Find map. Return a struct with init map, end map (nb_line) and height
t_fmap	find_map(char *filename)
{
	t_fmap	f_map;
	int		i;
	int		ffd;
	int		flm_f;
	char	*data_line;

	i = 0;
	f_map.width = 0;
	f_map.height = 0;
	flm_f = 0;
	data_line = NULL;
	ffd = open_file_and_check_ext(filename, ".cub");
	while (data_line || i == 0)
	{
		data_line = get_next_line(ffd);
		if (map_compatible_line(data_line) == 1)
		{
			if (flm_f == 0)
			{
				f_map.l_start = i;
				flm_f = 1;
			}
			f_map.width = compare_line_size(f_map.width, data_line);
			f_map.height++;
		}
		else if (map_compatible_line(data_line) != 1 && flm_f == 1)
			return (f_map);
		free(data_line);
		i++;
	}
	close(ffd);
	return (f_map);
}
