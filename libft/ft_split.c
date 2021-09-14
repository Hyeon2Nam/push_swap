/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:59:16 by riiringim         #+#    #+#             */
/*   Updated: 2021/09/14 13:43:31 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cutnum(char const *s, char c)
{
	size_t	cnt;

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

static void	ft_free(char **arr)
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

static void	do_split(char **str, char const *s, char c)
{
	size_t	size;
	char	*start;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				++s;
			size = s - start + 1;
			str[i] = (char *)malloc(size);
			if (!str)
			{
				free(str[i]);
				return ;
			}
			ft_strlcpy(str[i++], start, size);
		}
		else
			++s;
	}
	str[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * (ft_cutnum(s, c) + 1));
	if (!str)
	{
		ft_free(str);
		return (NULL);
	}
	do_split(str, s, c);
	return (str);
}
