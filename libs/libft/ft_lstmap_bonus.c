/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:07:08 by samperez          #+#    #+#             */
/*   Updated: 2024/11/08 10:47:05 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;
	t_list	*tmp;

	if (!lst || !del)
		return (NULL);
	else
	{
		tmp = lst;
		res = NULL;
		while (tmp)
		{
			node = ft_lstnew(0);
			if (!node)
			{
				ft_lstclear(&res, del);
				return (NULL);
			}
			node->content = f(tmp->content);
			ft_lstadd_back(&res, node);
			tmp = tmp->next;
		}
		return (res);
	}
}
