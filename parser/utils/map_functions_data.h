/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_data.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:36:39 by marvin            #+#    #+#             */
/*   Updated: 2023/05/02 13:40:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_FUNCTIONS_DATA_H
# define MAP_FUNCTIONS_DATA_H

// Utils and flags for save_map function
typedef struct s_smu
{
	int			i;
	int			ffd;
	char		*map_line;
}				t_smu;

// Utils and flags for find_map_struct
typedef struct s_fmu
{
	int			i;
	int			ffd;
	int			flm_f;
}				t_fmu;

#endif
