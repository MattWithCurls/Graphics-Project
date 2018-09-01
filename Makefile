# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msteer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/01 16:32:36 by msteer            #+#    #+#              #
#    Updated: 2018/09/01 17:10:50 by msteer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc -o
FLAG = -Wall -Werror -Wextra
MLXFLAG = -l mlx -framework OpenGL -framework AppKit
INC = -I ./includes
SRC = test.c \
	  drawline.c
OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME):
	@make -C ./libftgnl/
	@$(CC) $(NAME) $(SRC) $(FLAG) $(INC) ./libftgnl/libftgnl.a $(MLXFLAG)

clean:
	@make clean -C ./libftgnl/

fclean: clean
	@make fclean -C ./libftgnl/
	@$(RM) $(NAME)

re: fclean all
