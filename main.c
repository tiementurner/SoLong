/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 16:41:55 by tblanker      #+#    #+#                 */
/*   Updated: 2021/10/07 15:49:57 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	load_sprite(t_sprite *sprite, void *mlx)
{
	sprite->img = mlx_png_file_to_image(mlx, "lelijkerd.png", &sprite->width, &sprite->height);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bits_per_pixel, &sprite->line_length, &sprite->endian);
//	printf("%p\n", mlx->addr);
}

int main()
{
	t_mlx	mlx;
	
	ft_putstr_fd("Number of moves: 0\n\n", 1);
	mlx.movement.x_pos = 180;
	mlx.movement.y_pos = 180;
	mlx.movement.key_is_hold = 0;
	mlx.width = 800;
	mlx.height = 800;
	mlx.mlx = mlx_init();
	load_sprite(&mlx.sprite, mlx.mlx);
	mlx.window = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "SoLong");
	mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	mlx_hook(mlx.window, 17, 1L << 17, &close_window, &mlx);
	mlx_hook(mlx.window, 02, 1L << 0, &key_press_hook, &mlx);
	mlx_hook(mlx.window, 03, 1L << 1, &key_release_hook, &mlx);
	mlx_loop_hook(mlx.mlx, render, &mlx);
//	render(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
