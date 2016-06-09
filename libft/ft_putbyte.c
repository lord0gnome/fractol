/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbyte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 16:06:09 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/25 14:39:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbyte(unsigned char byte)
{
	unsigned char	temp;
	unsigned char	table[8];
	size_t			i;
	size_t			j;

	temp = byte;
	i = 0;
	j = 8;
	while (i != 0)
	{
		temp = byte;
		temp <<= j;
		if (temp >>= i + j-- != 0)
			table[i++] = '1';
		else
			table[i++] = '0';
	}
	i = 0;
	ft_putchar('[');
	while (i != 8)
	{
		ft_putchar(table[i++]);
		ft_putchar(' ');
	}
	ft_putchar(']');
}
