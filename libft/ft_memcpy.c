/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:45:03 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/10 17:20:20 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*a;
	char			*b;

	a = (char *)dst;
	b = (char *)src;
	while (n)
	{
		*a++ = *b++;
		n--;
	}
	return (dst);
}
