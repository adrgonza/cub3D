/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:56:57 by marvin            #+#    #+#             */
/*   Updated: 2023/06/21 13:12:12 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

// Check if the line contains a time of line compatible with a map
// If data_line is "\n" return 0
// If its true return(1) if not, return(0)
int	mapl_compat(char *data_line)
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

// Initialize find_map parameters to 0
void	init_find_map_params(t_fmap *f_map, t_fmu *fmu,
		char *filename, char **dataline)
{
	fmu->i = 0;
	fmu->flm_f = 0;
	fmu->ffd = open_file_and_check_ext(filename, ".cub");
	f_map->width = 0;
	f_map->height = 0;
	*dataline = NULL;
}

// Find map. Return a struct with init map, end map (nb_line) and height
t_fmap	find_map(char *filename)
{
	t_fmap	f_map;
	t_fmu	fmu;
	char	*data_line;

	init_find_map_params(&f_map, &fmu, filename, &data_line);
	while (data_line || fmu.i == 0)
	{
		data_line = get_next_line(fmu.ffd);
		if (mapl_compat(data_line) == 1)
		{
			if (fmu.flm_f++ == 0)
				f_map.l_start = fmu.i;
			f_map.width = compare_line_size(f_map.width, data_line);
			f_map.height++;
		}
		else if (mapl_compat(data_line) != 1 && fmu.flm_f > 0)
		{
			free(data_line);
			close(fmu.ffd);
			return (f_map);
		}
		free(data_line);
		fmu.i++;
	}
	return (f_map);
}
