/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:26:11 by riiringim         #+#    #+#             */
/*   Updated: 2021/08/20 15:45:56 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void error_handler(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

static int ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int ft_atoi(const char *str)
{
	long long res;
	int sign;
	int i;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			error_handler();
		else
			res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res * sign > 2147483647 || res * sign < -2147483648)
		error_handler();
	return (res * sign);
}
