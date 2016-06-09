/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strexpand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:10:43 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/16 15:23:04 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strexpand(char *str)
{
	int	i;
	int	cfe;

	cfe = (int)ft_strlen(str) - 1;
	while ((str[cfe] == ' ' || str[cfe] == '\t') && cfe >= 0)
		cfe--;
	i = 0;
	while (str[i] && i != cfe)
	{
		while ((str[i] == '\t' || str[i] == ' ') && str[i])
			i++;
		while (str[i] != '\t' && str[i] != ' ' && str[i] && i <= cfe)
			ft_putchar(str[i++]);
		if (i < cfe)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			ft_putchar(' ');
		}
		i++;
	}
}
