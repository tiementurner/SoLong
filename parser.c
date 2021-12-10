#include "header.h"

static	int		count_lines_in_file(int fd)
{
	char	buf[42];
	int		i;
	int		j;
	int		lines;

	lines = 0;
	j = 0;
	while (read(fd, buf, 42))
	{
		if (buf[0] == '\n' && j == 0)
			put_error ("Invalid map: first line in file is empty");
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				if (buf[i - 1] == '\n')
					break;
				lines++;
			}
			i++;
		}
		j++;
	}
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

char			*parse(char **av, t_mlx *engine)
{
	int		map_fd;
	char	*line;
	int		i;
	int		lines;

	map_fd = open(av[1], O_RDONLY);
	lines = count_lines_in_file(map_fd);
	engine->map = (char **)malloc(sizeof(char *) * lines);
	close(map_fd);
	map_fd = open(av[1], O_RDONLY);
	i = 0;
	while (i < lines)
	{
		get_next_line(map_fd, &line);
		engine->map[i] = (char *)malloc(sizeof(char) * ft_strlen(line));
		fill_map_line(engine->map[i], line);
		i++;
	}
	return ("ds");
}
