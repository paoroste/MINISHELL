# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paoroste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 16:53:04 by paoroste          #+#    #+#              #
#    Updated: 2017/10/24 14:31:00 by paoroste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB_PATH = libft/
LIB = $(LIB_PATH)/libft.a
FLAGS = -Wall -Wextra -Werror

SRC = main.c tools.c exec_command.c cd.c echo.c setenv.c\
	  signal.c unsetenv.c

all: $(NAME)

$(NAME):
	@echo "\033[33m" "Compiling" [ $(NAME) ]. "\033[31m"
	@make -C $(LIB_PATH)
	@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)
	@echo "\033[32m" "minishell has been Created" "\033[0m"

clean:
	@echo "\033[33m" "Deleting" "\033[34m"
	make -C $(LIB_PATH) clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all
