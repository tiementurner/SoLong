# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tblanker <tblanker@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/06 13:45:54 by tblanker      #+#    #+#                  #
#    Updated: 2021/12/10 14:53:19 by tblanker      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC_FLAGS = -Wall -Werror -Wextra 

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC_FLAGS += -D LINUX
    CCL_FLAGS += -lXext -lX11 -lm
    MINILIBX = libmlx.a
    MINILIBX_D = minilibx-linux
endif
ifeq ($(UNAME_S),Darwin)
    CC_FLAGS += -D OSX
    CCL_FLAGS += -framework AppKit -framework OpenGL
    MINILIBX = libmlx.dylib
    MINILIBX_D = minilibx
endif

NAME = SoLong

CC = clang

FILES = main.c pixel_functions.c key_handling.c draw.c movement.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c parser.c error.c

OFILES = $(FILES:.c=.o)

LIBS = libmlx.dylib -lft

LIBFT	= libft.a

all : $(NAME)

$(NAME) : $(OFILES) $(LIBFT) $(MINILIBX)
	@$(CC)	$(CCL_FLAGS) $(FILES) $(LIBS)	-o $(NAME)

#
%.o: %.c
	$(CC) -Ilft  -o $@ -c $< 
#
$(LIBFT) :
	$(MAKE) -C libft
	@mv	libft/libft.a .

$(MINILIBX)	:
	$(MAKE) -C $(MINILIBX_D)
	@mv	$(MINILIBX_D)/$(MINILIBX) .

clean	:
	rm -rf $(OFILES)
	$(MAKE) clean -C libft
	$(MAKE)	clean -C $(MINILIBX_D)

fclean	:	clean
	rm -rf libmlx.dylib libft.a $(NAME)
	
re	:	fclean all