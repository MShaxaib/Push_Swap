/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:20:45 by mshazaib          #+#    #+#             */
/*   Updated: 2024/02/19 13:11:46 by mshazaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	ft_atol(const char *str)
{
	int			i;
	long long	sgn;
	long long	num;

	i = 0;
	num = 0;
	sgn = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == 0)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (2147483648);
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	if (sgn == 1 && num > 2147483647)
		return (num);
	if (sgn == -1 && num * sgn < -2147483648)
		return (sgn * num);
	return (num * sgn);
}
