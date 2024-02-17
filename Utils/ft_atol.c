/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:20:45 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 20:48:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

long	ft_atol(const char *str)
{
	int i;
	long long sgn;
	long long num;

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
