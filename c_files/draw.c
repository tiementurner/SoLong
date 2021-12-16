/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 13:15:30 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/16 12:12:03 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	draw_background(t_mlx *engine)
{
	int	x;
	int	y;

	x = y = 0;
	while (x < engine->width)
	{
		y = 0;
		while (y < engine->height)
		{
			pixel_put(engine, x, y, 0);
			y++;
		}
		x++;
	}
}

unsigned	int	get_sprite_color(t_sprite *sprite, int x, int y)
{
	unsigned int	color;
	int				step_x;
	int				step_y;

	step_x = sprite->width / 40;
	step_y = sprite->height / 40;
	color = retrieve_texture_pixel(sprite, x * step_x, y * step_y);
	if (color == 16777215)
		return (0);
	return (color);
}

int	render(t_mlx	*engine)
{
	int	x, y;

	x = 0;
	y = 0;
	draw_background(engine);
	move(engine);
	while (x < engine->width)
	{
		while (y < engine->height)
		{
			if (x < engine->player.position.x + 40 &&
					x > engine->player.position.x &&
				y < engine->player.position.y + 40 &&
					y > engine->player.position.y)
				pixel_put(engine, x , y, get_sprite_color(&engine->sprite,
						x - engine->player.position.x,
						y - engine->player.position.y));
			y++;	
		}
		y = 0;
		x++;
	}
	mlx_sync(1, engine->img);
	mlx_put_image_to_window(engine->mlx, engine->window, engine->img, 0, 0);
	mlx_sync(3, engine->window);
	return (0);
}
