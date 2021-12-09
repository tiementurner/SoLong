#include "header.h"

void	put_error(char *error)
{
	ft_putstr_fd("Error:  ", 1);
	ft_putstr_fd(error, 1);
	ft_putstr_fd("\n", 1);
	exit(1);
}