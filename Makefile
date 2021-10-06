# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tblanker <tblanker@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/06 13:45:54 by tblanker      #+#    #+#                  #
#    Updated: 2021/10/06 15:04:10 by tblanker      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC_FLAGS = -Wall -Werror -Wextra 

NAME = SoLong

CC = clang

FILES = main.c pixel_functions.c key_handling.c

OFILES = $(FILES:.c=.o)

LIBS = libmlx.dylib -lft

MINILIBX = libmlx.dylib

LIBFT	= libft.a

ALL = $(NAME)

$(NAME) : $(OFILES) $(LIBFT) $(MINILIBX)
	@$(CC)	$(CCL_FLAGS) $(FILES) $(LIBS)	-o $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -Ilft  -o $@ -c $<

$(LIBFT) :
	$(MAKE) -C libft
	@mv	libft/libft.a .

$(MINILIBX)	:
	$(MAKE) -C minilibx
	@mv	minilibx/libmlx.dylib .

clean	:
	rm -rf $(OFILES)
	$(MAKE) clean -C libft
	$(MAKE)	clean -C minilibx

fclean	:	clean
	rm -rf libmlx.dylib libft.a $(NAME)
	
re	:	fclean all