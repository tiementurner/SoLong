/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 13:42:33 by tblanker      #+#    #+#                 */
/*   Updated: 2021/10/07 15:24:47 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>//
#include <stdlib.h>

typedef	struct	s_sprite
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	height;
	int		width;
}				t_sprite;

typedef	struct	s_move	{
	int		up;
	int		down;
	int		left;
	int		right;
	int		x_pos;
	int		y_pos;
	int		key_is_hold;
}				t_move	;

typedef struct s_mlx	{
	void		*mlx;
	void		*window;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_count;
	int			width;
	int			height;
	t_move		movement;
	t_sprite	sprite;
}				t_mlx	;

void			pixel_put(t_mlx *data, int x, int y, int color);
unsigned int	retrieve_texture_pixel(t_sprite *data, int x, int y);

int		render(t_mlx	*mlx);

int		key_press_hook(int keycode, t_mlx *mlx);
int		key_release_hook(int keycode, t_mlx *mlx);
int		close_window(t_mlx *mlx);

void	move(t_mlx *mlx);