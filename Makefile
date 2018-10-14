# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbolilyi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 16:42:45 by dbolilyi          #+#    #+#              #
#    Updated: 2018/08/02 19:17:28 by dbolilyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	SRC/draw_menu.c \
		SRC/draw_menu2.c \
		SRC/draw.c \
		SRC/fractols1.c \
		SRC/fractols2.c \
		SRC/hooks.c \
		SRC/switch.c \
		SRC/toimage.c \
		SRC/main.c

OBJ = $(SRC:.c=.o)

ERRFL = -Wall -Wextra -Werror

FL = -lmlx -framework OpenGL -framework AppKit -o3

PRINT = yes

all: $(NAME)

$(OBJ): %.o: %.c
	@echo "\033[93mCompiling \033[0m$@"
	@cc $(ERRFL) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "\033[93mCompiling libft\033[0m"
	@make -C ./libft
	@echo "\033[93mCompiling fractol\033[0m"
	@gcc $(ERRFL) $(FL) -L libft/ ./libft/libft.a -o $@ $(OBJ)
	@echo "\033[92mDONE\033[0m"
	

#$(ERRFL) -I fractol.h -c $< -o $@

clean:
	@echo "\033[91mDeleting libft objects\033[0m"
	@make -C libft/ clean
	@echo "\033[91mDeleting fractol objects\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[91mDeleting libft.a\033[0m"
	@make -C libft/ fclean
	@echo "\033[91mDeleting fractol\033[0m"
	@rm -f $(NAME)

re: fclean \
	all

.PHONY: all clean fclean re libft1

.NOTPARALLEL: all clean fclean re libft1
