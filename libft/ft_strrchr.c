/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:42:15 by fasare            #+#    #+#             */
/*   Updated: 2023/05/31 18:12:29 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == (char) c)
			return ((char *)s + i);
	return (NULL);
}

/*
ft_strrchr locates the last occurrence
of a character in a string. The function
takes in two parameters, the string(const char *) s,
and  character (int c) to be found.
*/