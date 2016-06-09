/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 14:11:04 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/02 14:15:20 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **first)
{
	size_t	i;
	t_list	*temp;

	i = 0;
	temp = *first;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
