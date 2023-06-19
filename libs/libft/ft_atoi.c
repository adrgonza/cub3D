/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <adrgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:55:43 by mcordoba          #+#    #+#             */
/*   Updated: 2023/06/19 20:03:30 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	over_num(unsigned long long num, int sign)
{
	if (sign == -1 && num >= 9223372036854775807)
		return (0);
	if (sign == 1 && num >= 9223372036854775807)
		return (-1);
	return (num);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			spc;
	int			sign;

	num = 0;
	spc = 0;
	sign = 1;
	while (str[spc] == '\t' || str[spc] == '\n' || str[spc] == '\v'
		|| str[spc] == '\f' || str[spc] == '\r' || str[spc] == ' ')
		spc++;
	if (str[spc] == '-')
	{
		sign = -1;
		spc++;
	}
	else if (str[spc] == '+')
		spc++;
	while (ft_isdigit(str[spc]))
	{
		num = (num * 10) + (str[spc] - '0');
		spc++;
	}
	num = over_num(num, sign);
	return (num * sign);
}
