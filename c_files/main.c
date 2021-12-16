/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 16:41:55 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/16 21:03:37 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	t_mlx	engine;

	if (ac != 2)
		put_error("Invalid amount of arguments: Usage:  ./SoLong [file]", &engine);
	parse(av, &engine);
	validate_map(&engine);
	ft_putstr_fd("Number of moves: 0\n\n", 1);
	init_player(&engine);
	init_mlx(&engine);
	return (0);
}
