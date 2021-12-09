#include "header.h"

char	*parse(char **av)
{
	int		map_fd;
	char	*line;
	int		line_length;

	printf("%s\n", av[1]);
	map_fd = open(av[1], O_RDONLY);

	while (get_next_line(map_fd, &line))
	{
		line_length = ft_strlen(line);
		
		printf("%s", line);
	}
	return ("ds");
}
