/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 13:42:33 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/16 17:10:30 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "gnl/get_next_line.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef	struct	s_position
{
	int 		x;
	int			y;	
}				t_position	;

typedef	struct	s_sprite
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int 		height;
	int			width;
}				t_sprite;

typedef	struct	s_player	{
	int			up;
	int			down;
	int			left;
	int			right;
	t_position	position;
}				t_player	;


typedef	struct	s_map	{
	char		**grid;
	int			lines;
	t_position	collectible;
	t_position	starting_pos;
	t_position	exit;
}				t_map	;

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
	t_player	player;
	t_sprite	sprite;
	int			key_is_held;
	t_map		map;
}				t_mlx	;

void			pixel_put(t_mlx *data, int x, int y, int color);
unsigned int	retrieve_texture_pixel(t_sprite *data, int x, int y);

void			init_player(t_mlx *engine);
void			init_mlx(t_mlx *engine);

int				render(t_mlx	*engine);

int				key_press_hook(int keycode, t_mlx *engine);
int				key_release_hook(int keycode, t_mlx *engine);
int				close_window(t_mlx *engine);

void			move(t_mlx *engine);

void			put_error(char *error, t_mlx *engine);
void			free_map(t_map *map);

void			parse(char **av, t_mlx *engine);
void			validate_map(t_mlx *engine);


#endif
