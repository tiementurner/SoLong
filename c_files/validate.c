/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 11:43:16 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/16 21:12:02 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	rectangular_map_check(char **grid, int last_line)
{
	int	i;
	int	initial_length;
	
	i = 0;
	last_line = 6;
	initial_length = ft_strlen(grid[i]);
	while(grid[i])
	{
		if ((int)ft_strlen(grid[i]) != initial_length && grid[i] != NULL)
			return (0);
		i++;
	}
	return (1);
}

static	int		check_for_invalid_chars(char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while(grid[y][x])
		{
			if (grid[y][x] != '0' && grid[y][x] != '1' && grid[y][x] != 'P' &&
					grid[y][x] != 'E' && grid[y][x] != 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	validate_map(t_mlx *engine)
{
	if (!rectangular_map_check(engine->map.grid, engine->map.lines))
		put_error("Map is not rectangular.", engine);
	if(!check_for_invalid_chars(engine->map.grid))
		put_error("Invalid characters in map. Only [1,0,C,P,E] \
allowed. (delete spaces at end of line)", engine);
}
