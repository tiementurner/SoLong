/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 16:41:55 by tblanker      #+#    #+#                 */
/*   Updated: 2021/10/06 16:07:09 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
int main()
{
	t_mlx	mlx;
	
	mlx.movement.x_pos = 180;
	mlx.movement.y_pos = 180;
	mlx.width = 800;
	mlx.height = 800;
	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "SoLong");
	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	mlx_hook(mlx.window, 02, 1L << 0, &key_press_hook, &mlx);
	mlx_hook(mlx.window, 03, 1L << 1, &key_release_hook, &mlx);
	mlx_loop_hook(mlx.mlx, render, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}


void	move(t_mlx *mlx)
{
	if (mlx->movement.up == 1 && mlx->movement.y_pos > 20 && mlx->movement.key_is_hold == 0)
	{
//		mlx->movement.up = 0;
		mlx->movement.key_is_hold = 1;
		mlx->movement.y_pos -= 20;
	}
	if (mlx->movement.down == 1 && mlx->movement.y_pos < mlx->height - 40 && mlx->movement.key_is_hold == 0)
	{
		mlx->movement.key_is_hold = 1;
		mlx->movement.y_pos += 20;
	}
	if (mlx->movement.right == 1 && mlx->movement.x_pos > 20)
		mlx->movement.x_pos -= 20;
	if (mlx->movement.left == 1 && mlx->movement.x_pos < mlx->height - 40)
		mlx->movement.x_pos += 20;
}

int	render(t_mlx	*mlx)
{
	int	x, y;

	move(mlx);
	x = y = 0;
	while (x < mlx->width)
	{
		y = 0;
		while (y < mlx->height)
		{
			pixel_put(mlx, x, y, 0);
			y++;
		}
		x++;
	}
	x = y = 0;
	while (x < mlx->width)
	{
		while (y < mlx->height)
		{
			if (x < mlx->movement.x_pos + 20 && x > mlx->movement.x_pos && y < mlx->movement.y_pos + 20 && y > mlx->movement.y_pos)
				pixel_put(mlx, x , y, 255);
			y++;	
		}
		y = 0;
		x++;
	}
	mlx_sync(1, mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	mlx_sync(3, mlx->window);
	return (0);
}