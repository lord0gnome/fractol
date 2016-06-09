/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:21:49 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/10 18:27:47 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char	*a;
	char	*b;

	a = s1;
	b = (char *)s2;
	if (!*b)
		return (s1);
	while (*a)
		a++;
	while (*b)
		*a++ = *b++;
	*a = '\0';
	return (s1);
}
