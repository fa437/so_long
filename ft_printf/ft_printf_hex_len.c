/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:19:04 by fasare            #+#    #+#             */
/*   Updated: 2023/06/26 19:19:59 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		len ++;
		number = number / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int number, const char format)
{
	if (number >= 16)
	{
		ft_put_hex(number / 16, format);
		ft_put_hex(number % 16, format);
	}
	else
	{
		if (number <= 9)
			ft_putchar((number + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((number - 10 + 'a'));
			if (format == 'X')
				ft_putchar((number - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int number, const char format)
{
	if (number == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(number, format);
	return (hex_len(number));
}
