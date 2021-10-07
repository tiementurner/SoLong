/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 16:49:43 by tblanker      #+#    #+#                 */
/*   Updated: 2021/10/07 13:57:16 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		close_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
	return (0);
}

int		key_press_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->movement.up = 1;
	if (keycode == 1)
		mlx->movement.down = 1;
	if (keycode == 2)
		mlx->movement.left = 1;
	if (keycode == 0)
		mlx->movement.right = 1;
	 if (keycode == 53)
		close_window(mlx);
	return (0);
}

int		key_release_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
	{
		mlx->movement.key_is_hold = 0;
		mlx->movement.up = 0;
	}
	if (keycode == 1)
	{
		mlx->movement.down = 0;
		mlx->movement.key_is_hold = 0;
	}
	if (keycode == 2)
	{
		mlx->movement.left = 0;
		mlx->movement.key_is_hold = 0;
	}
	if (keycode == 0)
	{
		mlx->movement.right = 0;
		mlx->movement.key_is_hold = 0;
	}
	return (0);
}
