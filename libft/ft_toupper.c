/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:50:32 by fasare            #+#    #+#             */
/*   Updated: 2023/05/19 11:37:24 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int alpha)
{
	if (alpha >= 'a' && alpha <= 'z')
		alpha -= 32;
	return (alpha);
}

/*conventing alphabets to upper using ascii values*/