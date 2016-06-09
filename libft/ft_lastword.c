/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:09:33 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/16 15:21:41 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lastword(char *str)
{
	int		i;
	size_t	count;

	i = ft_strlen(str) - 1;
	count = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
	{
		count++;
		i--;
	}
	while (count--)
		ft_putchar(str[++i]);
}
