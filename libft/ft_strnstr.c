/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:00:19 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/09 16:32:38 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t		i;
	size_t		i2;
	size_t		place;

	i = 0;
	i2 = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < n)
	{
		place = i;
		while ((big[i] == little[i2]) && i < n)
		{
			i++;
			i2++;
			if (little[i2] == '\0')
				return ((char *)big + (i - i2));
			if (big[i] == '\0')
				return (NULL);
		}
		i2 = 0;
		i = place;
		i++;
	}
	return (NULL);
}
