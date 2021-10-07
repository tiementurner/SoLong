/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 13:14:44 by tblanker      #+#    #+#                 */
/*   Updated: 2021/10/07 15:48:35 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	execute_move(int *position, int *key_is_hold, int move_count, int move_value)
{
	*key_is_hold = 1;
	*position += move_value;
	move_count++;
	ft_putstr_fd("Number of moves: ", 1);
	ft_putnbr_fd(move_count, 1);
	ft_putstr_fd("\n\n", 1);
//	ft_putchar()
//	printf("%d\n", move_count);
	return (move_count);
}

void	move(t_mlx *mlx)
{
	static	int	move_count;

	if (mlx->movement.up == 1 && mlx->movement.y_pos > 40 && mlx->movement.key_is_hold == 0)
		move_count = execute_move(&mlx->movement.y_pos, &mlx->movement.key_is_hold, move_count, -40);
	if (mlx->movement.down == 1 && mlx->movement.y_pos < mlx->height - 80 && mlx->movement.key_is_hold == 0)
		move_count = execute_move(&mlx->movement.y_pos, &mlx->movement.key_is_hold, move_count, 40);
	if (mlx->movement.right == 1 && mlx->movement.x_pos > 40 && mlx->movement.key_is_hold == 0)
		move_count = execute_move(&mlx->movement.x_pos, &mlx->movement.key_is_hold, move_count, -40);
	if (mlx->movement.left == 1 && mlx->movement.x_pos < mlx->height - 80 && mlx->movement.key_is_hold == 0)
		move_count = execute_move(&mlx->movement.x_pos, &mlx->movement.key_is_hold, move_count, 40);
}