/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:20 by fasare            #+#    #+#             */
/*   Updated: 2023/05/19 11:37:22 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int alpha)
{
	if (alpha >= 'A' && alpha <= 'Z')
		alpha += 32;
	return (alpha);
}

/*conventing alphabets to upper using ascii values*/