/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:28:08 by tblanker      #+#    #+#                 */
/*   Updated: 2021/12/16 17:05:31 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	int		count_lines_in_file(int fd, t_mlx *engine)
{
	int		gnl;
	int		lines;
	char	*line;

	engine->map.lines = 0;
	lines = 0;
	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line, 0 , 0);
		if (line[0] == '\0')
		{
			gnl = 1;
			break;
		}
		free(line);
		lines++;
	}
	if (gnl == 1)
	 	free(line);
	return (lines);
}

static	void	fill_map_line(char *map_line, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		map_line[i] = line[i];
		i++;
	}
	map_line[i] = '\0';
}

void			parse(char **av, t_mlx *engine)
{
	int		map_fd;
	char	*line;
	int		i;

	map_fd = open(av[1], O_RDONLY);
	engine->map.lines = count_lines_in_file(map_fd, engine);
	engine->map.grid = (char **)malloc(sizeof(char *) * engine->map.lines + 1);
	if (!engine->map.grid)
		put_error("Memory allocation failure, fix your pc bro!", engine);
	engine->map.grid[engine->map.lines] = NULL;
	close(map_fd);
	map_fd = open(av[1], O_RDONLY);
	i = 0;
	while (i < engine->map.lines)
	{
		get_next_line(map_fd, &line, 1, i);
		engine->map.grid[i] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
		if (!engine->map.grid[i])
			put_error("Memory allocation failure, fix your pc bro!", engine);
		fill_map_line(engine->map.grid[i], line);
		free(line);
		i++;
	}
}
