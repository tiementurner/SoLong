/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:27:54 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/16 12:25:59 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_error(char *error, t_mlx *engine)
{
	free_map(&engine->map);
	ft_putstr_fd("Error:\n", 1);
	ft_putstr_fd(error, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

void	free_map(t_map *map)
{
	int		i;
//	char	*pointer;

	i = 0;
	if (map->grid)
	{
		while(i < map->lines)
		{
		//	pointer = map->grid[i];
		//	free(pointer);	
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
}
