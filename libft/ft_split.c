/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:59:16 by riiringim         #+#    #+#             */
/*   Updated: 2021/08/26 15:59:39 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_cutnum(char const *s, char c)
{
	size_t cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (cnt);
}

static void ft_free(char **arr)
{
	int len;
	int i;

	len = 0;
	while (arr[len])
		len++;
	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}

char **ft_split(char const *s, char c)
{
	char **str;
	char *start;
	size_t i;
	size_t size;

	if (!(str = (char **)malloc(sizeof(char *) * ft_cutnum(s, c) + 1)))
	{
		ft_free(str);
		return (0);
	}
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				++s;
			size = s - start + 1;
			if (!(str[i] = (char *)malloc(size)))
			{
				free(str[i]);
				return (0);
			}
			ft_strlcpy(str[i++], start, size);
		}
		else
			++s;
	}
	str[i] = 0;
	return (str);
}
