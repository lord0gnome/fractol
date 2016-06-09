/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:29:34 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/14 16:06:05 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < dstlen)
		return (size + srclen);
	i = (int)size;
	while (*dst && i >= 0)
	{
		dst++;
		i--;
	}
	while (*src && i-- > 1)
		*dst++ = *src++;
	if (i == 1)
		*dst++ = '\0';
	while (*dst)
		*dst++ = '\0';
	return (srclen + dstlen);
}
