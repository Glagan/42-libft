/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:25:31 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/14 14:17:45 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstmap(t_list *lst, void *(*f)(void*))
{
	t_list	*first;
	t_list	*new;

	first = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
			return (NULL);
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
