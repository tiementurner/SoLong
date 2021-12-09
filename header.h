/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 13:42:33 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/09 17:39:27 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>//
#include <stdlib.h>
#include <fcntl.h>

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

typedef	struct	s_position	{
	int		up;
	int		down;
	int		left;
	int		right;
	int		x;
	int		y;
}				t_position	;

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
	t_position	position;
	t_sprite	sprite;
	int			key_is_held;
}				t_mlx	;

void			pixel_put(t_mlx *data, int x, int y, int color);
unsigned int	retrieve_texture_pixel(t_sprite *data, int x, int y);

int		render(t_mlx	*mlx);

int		key_press_hook(int keycode, t_mlx *mlx);
int		key_release_hook(int keycode, t_mlx *mlx);
int		close_window(t_mlx *mlx);

void	move(t_mlx *mlx);

void	put_error(char *error);

char	*parse(char **av);