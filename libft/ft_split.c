/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:15:03 by fasare            #+#    #+#             */
/*   Updated: 2023/06/06 11:38:18 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahswillnf <jahswillnf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:07:45 by jahswillnf        #+#    #+#             */
/*   Updated: 2022/12/31 13:09:11 by jahswillnf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_toklen(const char *s, char c)
{
	size_t	tok_num;

	tok_num = 0;
	while (*s)
	{
		if (*s != c)
		{
			++tok_num;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (tok_num);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	split = malloc(sizeof(char *) * (ft_toklen(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			split[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	split[i] = NULL;
	return ((char **)split);
}

/*
ft_split splits a string into an array of substrings
based on a delimiter.
ft_toklen is used to determine the num of tokens
in a string by counting the non-delimiter char
and skipping over the delimiters.
*/