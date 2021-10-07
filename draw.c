/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 13:15:30 by tblanker      #+#    #+#                 */
/*   Updated: 2021/10/07 15:46:44 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	draw_background(t_mlx *mlx)
{
	int	x, y;

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

int	render(t_mlx	*mlx)
{
	int	x, y;

	x = 0;
	y = 0;
	draw_background(mlx);
	while (x < mlx->width)
	{
		while (y < mlx->height)
		{
			if (x < mlx->movement.x_pos + 40 && x > mlx->movement.x_pos && y < mlx->movement.y_pos + 40 && y > mlx->movement.y_pos)
				pixel_put(mlx, x , y, get_sprite_color(&mlx->sprite, x - mlx->movement.x_pos, y - mlx->movement.y_pos));
			y++;	
		}
		y = 0;
		x++;
	}
	mlx_sync(1, mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	mlx_sync(3, mlx->window);
	move(mlx);
	return (0);
}
