/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 12:08:17 by guiricha          #+#    #+#             */
/*   Updated: 2015/12/05 12:18:25 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*new;
	t_list	*next;
	t_list	*last;

	new = NULL;
	new = f(lst);
	last = new;
	lst = lst->next;
	while (lst)
	{
		next = f(lst);
		last->next = next;
		last = next;
		lst = lst->next;
	}
	last->next = NULL;
	return (new);
}
