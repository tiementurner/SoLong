/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_handling.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 16:49:43 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/16 12:30:44 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		close_window(t_mlx *engine)
{
	mlx_destroy_image(engine->mlx, engine->img);
	mlx_destroy_window(engine->mlx, engine->window);
//	free_map(&engine->map);
	system("leaks SoLong");
	exit(0);
	return (0);
}

int		key_press_hook(int keycode, t_mlx *engine)
{
	if (engine->key_is_held == 1)
		return (0);
	if (keycode == 13)
		engine->player.up = 1;
	if (keycode == 1)
		engine->player.down = 1;
	if (keycode == 2)
		engine->player.right = 1;
	if (keycode == 0)
		engine->player.left = 1;
	 if (keycode == 53)
		close_window(engine);
	return (0);
}

int		key_release_hook(int keycode, t_mlx *engine)
{
	if (keycode == 13)
		engine->player.up = 0;
	if (keycode == 1)
		engine->player.down = 0;
	if (keycode == 0)
		engine->player.left = 0;
	if (keycode == 2)
		engine->player.right = 0;
	if (engine->player.up == 0 && engine->player.down == 0 &&
		engine->player.left == 0 && engine->player.right == 0)
		engine->key_is_held = 0;
	return (0);
}
