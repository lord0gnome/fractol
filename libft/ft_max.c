/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:06:40 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/16 15:22:35 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int *tab, unsigned int len)
{
	int	max;

	if (len == 0)
		return (0);
	max = tab[len - 1];
	len--;
	while (len)
	{
		if (tab[len - 1] > max)
			max = tab[len - 1];
		len--;
	}
	return (max);
}
