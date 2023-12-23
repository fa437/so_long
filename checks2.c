/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:02:38 by fasare            #+#    #+#             */
/*   Updated: 2023/12/07 18:02:38 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Count & allocate P E C
int	ft_ispec(t_frame *game)
{
	int	p;
	int	row;
	int	col;

	row = -1;
	p = 0;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			if (game->map[row][col] == 'P')
			{
				p++;
				game->player[0] = row;
				game->player[1] = col;
			}
			else if (game->map[row][col] == 'E')
				game->gate++;
			else if (game->map[row][col] == 'C')
				game->herbs++;
		}
	}
	return (p);
}

// checks ifpath is marked to C & E
int	check_path(t_frame *game, int **marked)
{
	int	row;
	int	col;
	int	exit;
	int	herbs;

	row = -1;
	exit = 0;
	herbs = 0;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			if ((game->map[row][col] == 'E') && (marked[row][col]))
				exit++;
			if ((game->map[row][col] == 'C') && (marked[row][col]))
				herbs++;
		}
	}
	if ((exit + herbs) == (game->herbs + 1))
	{
		return (1);
	}
	else
		return (ft_putendl_fd("Error: check map paths to C and E", 2), 0);
}

// Marks valid paths from the P pos recursively on the map
// using Depth first search algorithm to know where is accesible and not.
void	mark_path(t_frame *game, int row, int col, int **marked)
{
	if ((row < 0 || row >= game->rows) && (col < 0 || col >= game->cols))
		return ;
	if (game->map[row][col] != '1' && marked[row][col] != 1)
	{
		marked[row][col] = 1;
		mark_path(game, row, col + 1, marked);
		mark_path(game, row, col - 1, marked);
		mark_path(game, row + 1, col, marked);
		mark_path(game, row - 1, col, marked);
	}
}

// this checks if there is a valid path from the player
// to the exit and collectiobles
int	ispath(t_frame *game)
{
	int		**marked;
	int		valid;
	int		i;

	i = 0;
	valid = 1;
	marked = (int **)ft_calloc(game->rows, sizeof(int *));
	while (i < game->rows)
	{
		marked[i] = (int *)ft_calloc(game->cols, sizeof(int));
		i++;
	}
	mark_path(game, game->player[0], game->player[1], marked);
	valid = check_path(game, marked);
	while (--i >= 0)
		free(marked[i]);
	free(marked);
	return (valid);
}
