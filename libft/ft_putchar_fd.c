/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:07:17 by fasare            #+#    #+#             */
/*   Updated: 2023/05/31 13:08:24 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
the fd parameter is to allow writing the char c
to different dests based on the provided file descriptor.
fd can be set to 1 to write the char to the standard output
or it can be set to a file descriptor obtained by opening a
specific file to write the character to that file.
you can control where the output is directed, enabling 
the function to write chars to various files or input or output
resources as needed.
*/