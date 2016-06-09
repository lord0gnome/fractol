/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:11:58 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/10 18:20:40 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)dst;
	b = (char *)src;
	while (n > 0 && *b != c)
	{
		*a++ = *b++;
		n--;
	}
	if (n > 0)
	{
		*a = *b;
		a++;
		return (void *)a;
	}
	return (NULL);
}
