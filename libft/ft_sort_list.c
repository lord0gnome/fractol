/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:23:50 by guiricha          #+#    #+#             */
/*   Updated: 2016/01/25 14:46:30 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_i_list	*sort_list(t_i_list *lst, int (*cmp)(int, int))
{
	int			temp;
	t_i_list	*tmplst;
	t_i_list	*start;

	start = lst;
	tmplst = lst;
	if (!lst)
		return (lst);
	temp = lst->content;
	while (lst)
	{
		while (tmplst)
		{
			if (!cmp(lst->content, tmplst->content))
			{
				temp = lst->content;
				lst->content = tmplst->content;
				tmplst->content = temp;
			}
			tmplst = tmplst->next;
		}
		lst = lst->next;
		tmplst = lst;
	}
	return (start);
}
