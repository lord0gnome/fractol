/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:50:33 by guiricha          #+#    #+#             */
/*   Updated: 2016/04/26 14:54:00 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_tab(int *tab, unsigned int size)
{
	int				bck;
	unsigned int	index;
	unsigned int	j;

	index = 0;
	while (index < size)
	{
		j = index;
		while (j < size)
		{
			if (tab[index] > tab[j])
			{
				bck = tab[index];
				tab[index] = tab[j];
				tab[j] = bck;
			}
			j++;
		}
		index++;
	}
}
