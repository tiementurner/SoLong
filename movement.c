/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 13:14:44 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/10 14:25:55 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	execute_move(t_mlx *engine, int move_count)
{
	if (engine->position.up == 1 && engine->position.y > 40)
		engine->position.y -= 40;
	if (engine->position.down == 1 && engine->position.y < engine->height - 80)
		engine->position.y += 40;
	if (engine->position.left == 1 && engine->position.x > 40)
		engine->position.x -= 40;
	if (engine->position.right && engine->position.x < engine->width - 80)
		engine->position.x += 40;
	move_count++;
	ft_putstr_fd("Number of moves: ", 1);
	ft_putnbr_fd(move_count, 1);
	ft_putstr_fd("\n\n", 1);
	return (move_count);
}

void	move(t_mlx *engine)
{
	static	int	move_count;

	if ((engine->position.up == 1 || engine->position.down == 1 ||
		engine->position.left == 1 || engine->position.right == 1)
		&& engine->key_is_held == 0)
	{
		move_count = execute_move(engine, move_count);
		engine->key_is_held = 1;
	}
}
