/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:19:02 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/09 16:29:27 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		i2;
	int		place;

	i = 0;
	i2 = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i])
	{
		place = i;
		while (big[i] == little[i2])
		{
			i++;
			i2++;
			if (little[i2] == '\0')
				return ((char *)big + (i - i2));
		}
		i2 = 0;
		i = place;
		i++;
	}
	return (NULL);
}
