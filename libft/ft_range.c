/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:59:24 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/25 15:01:16 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	assign_size(int *dir, int startt, int endd)
{
	int size;
	int start;
	int end;

	start = startt;
	end = endd;
	size = 1;
	if (start > end)
		while (start > end)
		{
			start--;
			size++;
			*dir = 1;
		}
	else if (start < end)
		while (start < end)
		{
			start++;
			size++;
			*dir = 0;
		}
	else if (start == end)
		size = 1;
	return (size);
}

int				*ft_range(int start, int end)
{
	size_t	size;
	size_t	count;
	int		*table;
	int		dir;

	dir = 1;
	count = 0;
	size = assign_size(&dir, start, end);
	if (!(table = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	while (size)
	{
		if (dir)
			table[count++] = start--;
		else if (!dir)
			table[count++] = start++;
		size--;
	}
	return (table);
}
