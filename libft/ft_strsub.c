/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:59:50 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/03 14:46:49 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	i2;

	new = ft_strnew(len);
	if (!new)
		return (NULL);
	i = 0;
	i2 = 0;
	i2 += start;
	while (i < len && s[i2])
		new[i++] = s[i2++];
	return (new);
}
