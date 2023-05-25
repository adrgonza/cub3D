/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcordoba <mcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:00:46 by mcordoba          #+#    #+#             */
/*   Updated: 2023/05/25 18:23:56 by mcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	//t_cubdat cubdat;
	printf("\t\033[0;35m----> Cub3d <----\033[0m\n");
	if (errmanag(argc, argv))
		parser(argv[1]);
	//system("leaks cub3d");
	printf("\033[0;35m      ----> Cub3d END <----\033[0m\n");
	(void)argc;
	(void)argv;
	return (0);
}
