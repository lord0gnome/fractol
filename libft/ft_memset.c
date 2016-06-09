/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:11:34 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/10 17:25:53 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*t;

	t = (unsigned char *)b;
	while (n)
	{
		*t = (unsigned char)c;
		t++;
		n--;
	}
	return (b);
}
