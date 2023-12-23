/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:02:54 by fasare            #+#    #+#             */
/*   Updated: 2023/05/31 16:32:15 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	index = 0;
	while (*s)
	{
		f(index, s);
		s++;
		index++;
	}
}

/*
ft_striteri iterates over each character of the string s
and applies the function f to each character. The
function f takes two args: the index of the char and a ptr
to the char itself. It can modify the character if necessary.
*/