/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:27:54 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/14 16:27:55 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_error(char *error, t_mlx *engine)
{
	ft_putstr_fd("Error:\n", 1);
	ft_putstr_fd(error, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}

void	free_map(t_mlx *engine, int	lines)
{
	int	i;
	char	*pointer;

	i = 0;
	if (engine->map)
	{
		while(i < lines)
		{
			pointer = engine->map[i];
			free(pointer);
			i++;
		}
		free(engine->map);
	}
}
