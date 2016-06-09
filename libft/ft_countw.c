/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:12:13 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/16 15:22:16 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countw(char *str)
{
	int	numwords;

	numwords = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str && *str != ' ' && *str != '\t' && *str != '\n')
			numwords++;
		while (*str && *str != ' ' && *str != '\t' && *str != '\n')
			str++;
	}
	return (numwords);
}
