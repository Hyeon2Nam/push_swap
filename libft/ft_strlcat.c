/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riiringim <riiringim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:07:10 by riiringim         #+#    #+#             */
/*   Updated: 2020/12/29 20:46:39 by riiringim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dlen;

	dlen = ft_strlen(dst);
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && dlen + i < dstsize - 1)
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[i + dlen] = 0;
	if (dstsize < dlen)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + dlen);
}
