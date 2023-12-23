/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 08:47:48 by fasare            #+#    #+#             */
/*   Updated: 2023/05/28 16:11:33 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
we are iterating over each node in the linked
list and applying the function f to the content
of each node. the loop continues as long as lst is not null.
Inside the loop, f is called and passed the content of the
current node, lst->content. the provided function f to the
content of each node in the linked list.
*/