/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:48:45 by fasare            #+#    #+#             */
/*   Updated: 2023/05/31 13:14:47 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}

/*
This function takes a pointer to a memory location"s",
a value to fill that memory location with"c", and 
then a number of bytes to fill "n" as parameters. It loops
through the memory location starting from the end and
filling each byte with the given value "c", until it
has filled the specified number of bytes "n". Finally, 
it returns the pointer to the memory location that was
modified.
*/