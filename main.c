/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 16:41:55 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/14 16:24:39 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	load_sprite(t_sprite *sprite, void *mlx)
{
	sprite->img = mlx_png_file_to_image(mlx, "lelijkerd.png",
										&sprite->width, &sprite->height);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bits_per_pixel, 
										&sprite->line_length, &sprite->endian);
}

void	init_player(t_mlx *engine)
{
	engine->position.x = 180;
	engine->position.y = 180;
	engine->key_is_held = 0;
	engine->position.left = 0;
	engine->position.right = 0;
	engine->position.up = 0;
	engine->position.down = 0;
	engine->width = 800;
	engine->height = 800;
	engine->mlx = mlx_init();
	load_sprite(&engine->sprite, engine->mlx);
	engine->window = mlx_new_window(engine->mlx, engine->width,
									engine->height, "SoLong");
	engine->img = mlx_new_image(engine->mlx, engine->width, engine->height);
	engine->addr = mlx_get_data_addr(engine->img, &engine->bits_per_pixel,
									&engine->line_length, &engine->endian);
}	

int		main(int ac, char **av)
{
	t_mlx	engine;

	if (ac != 2)
		put_error("Invalid amount of arguments: Usage:  ./SoLong [file]", &engine);
	parse(av, &engine);
	ft_putstr_fd("Number of moves: 0\n\n", 1);
	init_player(&engine);
	mlx_hook(engine.window, 17, 1L << 17, &close_window, &engine);
	mlx_hook(engine.window, 02, 1L << 0, &key_press_hook, &engine);
	mlx_hook(engine.window, 03, 1L << 1, &key_release_hook, &engine);
	mlx_loop_hook(engine.mlx, render, &engine);
	mlx_loop(engine.mlx);
	return (0);
}
