/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 13:14:44 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/09 16:31:47 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	execute_move(t_mlx *mlx, int move_count)
{
	if (mlx->position.up == 1 && mlx->position.y > 40)
		mlx->position.y -= 40;
	if (mlx->position.down == 1 && mlx->position.y < mlx->height - 80)
		mlx->position.y += 40;
	if (mlx->position.left == 1 && mlx->position.x > 40)
		mlx->position.x -= 40;
	if (mlx->position.right && mlx->position.x < mlx->width - 80)
		mlx->position.x += 40;
	move_count++;
	ft_putstr_fd("Number of moves: ", 1);
	ft_putnbr_fd(move_count, 1);
	ft_putstr_fd("\n\n", 1);
	return (move_count);
}

void	move(t_mlx *mlx)
{
	static	int	move_count;

	if ((mlx->position.up == 1 || mlx->position.down == 1 || mlx->position.left == 1 || mlx->position.right == 1) && mlx->key_is_held == 0)
	{
		move_count = execute_move(mlx, move_count);
		mlx->key_is_held = 1;
	}
}
