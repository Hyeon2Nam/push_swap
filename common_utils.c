/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:00 by hyenam            #+#    #+#             */
/*   Updated: 2021/09/11 18:23:59 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

double	ft_sqrt(double num)
{
	double	res;
	int		i;

	res = 2;
	i = 0;
	while (i < 10)
	{
		res = (res + (num / res)) / 2;
		i++;
	}
	return (res);
}

void	ft_free(char **arr)
{
	int	len;
	int	i;

	len = 0;
	while (arr[len])
		len++;
	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}
