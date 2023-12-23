/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:03:01 by fasare            #+#    #+#             */
/*   Updated: 2023/12/07 18:03:01 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// checks if all collectibles are colllected
void	is_exit(t_frame *game, int row, int col)
{
	if (game->herbs != game->collected)
	{
		ft_putendl_fd("You must collect all herbs", 1);
		change_position(game, row, col);
	}
	else
	{
		ft_putendl_fd("GAME OVER! YOU WIN!!", 1);
		free_destroy(game);
	}
}

// using a diff exit sprite when all collectibles
// are collected
void	check_gate(t_frame *game)
{
	int	row;
	int	col;

	row = -1;
	if (game->herbs == game->collected)
	{
		while (++row < game->rows)
		{
			col = -1;
			while (++col < game->cols)
				if (game->map[row][col] == 'E')
					ft_put_img(game, game->door[1], row, col);
		}
	}
	else
		return ;
}

// move player accordoing to the element either 1 0 & C
void	move_wiz(t_frame *game, int row, int col)
{
	if (game->map[row][col] == '1')
		return ;
	else if (game->map[row][col] == '0' || game->map[row][col] == 'C')
	{
		if (game->map[row][col] == 'C')
		{
			game->map[row][col] = '0';
			game->collected++;
			check_gate(game);
		}
		change_position(game, row, col);
	}
	else if (game->map[row][col] == 'E')
		is_exit(game, row, col);
}

// key hook for changing player direction base on the key pressed
void	key_hook2(int keycode, t_frame *game)
{
	if (keycode == KEY_D)
	{
		if (game->direction != 'R')
		{
			game->wiz_img = game->wiz[0];
			ft_put_img(game, game->wiz_img, game->player[0], game->player[1]);
			game->direction = 'R';
		}
		else
			move_wiz(game, game->player[0], game->player[1] + 1);
	}
	else if (keycode == KEY_A)
	{
		if (game->direction != 'L')
		{
			game->wiz_img = game->wiz[1];
			ft_put_img(game, game->wiz_img, game->player[0], game->player[1]);
			game->direction = 'L';
		}
		else
			move_wiz(game, game->player[0], game->player[1] - 1);
	}
}

// hanldes all key pressed 
int	ft_key_hook(int keycode, t_frame *game)
{
	if (keycode == ESC_KEY)
		free_destroy(game);
	else if (keycode == KEY_D || keycode == KEY_A)
		key_hook2(keycode, game);
	else if (keycode == KEY_W)
		move_wiz(game, game->player[0] - 1, game->player[1]);
	else if (keycode == KEY_S)
		move_wiz(game, game->player[0] + 1, game->player[1]);
	return (0);
}
