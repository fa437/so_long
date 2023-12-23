/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:02:53 by fasare            #+#    #+#             */
/*   Updated: 2023/12/20 21:01:35 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check arg & number of arg. and launch graphics if all is good.
int	main(int argc, char **argv)
{
	t_frame	*game;

	if (argc != 2)
		return (ft_putendl_fd("Error: Invalid argument!", 2), 1);
	game = checker(argv[1]);
	if (game)
		launch_graphics(game);
	return (0);
}
