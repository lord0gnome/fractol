/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 13:50:37 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/16 15:29:31 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_split(char *s)
{
	int		i;
	int		j;
	int		c;
	char	**ret;
	int		index;

	ret = (char **)malloc(sizeof(char *) * (ft_countw(s) + 1));
	i = 0;
	index = -1;
	while (s[i])
	{
		index++;
		while ((ft_isspace(s[i])) && s[i])
			i++;
		c = 0;
		while (!ft_isspace(s[i]) && s[i + c])
			c++;
		ret[index] = (char *)malloc(sizeof(char) * (c + 1));
		j = 0;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i])
			ret[index][j++] = s[i++];
		ret[index][j] = '\0';
	}
	ret[index] = NULL;
	return (ret);
}
