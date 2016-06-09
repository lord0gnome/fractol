/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:16:22 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/10 18:28:30 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	size_t	length;
	char	*new;
	size_t	i;

	length = ft_strlen(s1);
	if (!(new = ft_strnew(length)))
		return (NULL);
	i = 0;
	while (i < (length))
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
