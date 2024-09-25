/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:25:06 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/24 10:03:50 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*list;
	t_list	*p;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	p = lst;
	while (p)
	{
		aux = ft_lstnew(f(p -> content));
		if (!aux)
		{
			ft_lstclear(&list, del);
			del(p->content);
			return (NULL);
		}
		ft_lstadd_back(&list, aux);
		p = p-> next;
	}
	return (list);
}
