/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 15:25:10 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/25 14:37:46 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char result;

	result = octet;
	while (octet)
	{
		result <<= 1;
		result |= octet & 1;
		octet >>= 1;
	}
	result <<= 1;
	return (result);
}
