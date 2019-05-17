# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filip <filip@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 12:59:55 by aashara-          #+#    #+#              #
#    Updated: 2019/05/12 19:26:48 by filip            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

ERROR=srcs/error/ft_errno.c\

LINE_EDITING=srcs/line_editing/check_symb.c\
			srcs/line_editing/line_editing.c\
			srcs/line_editing/line_editing2.c\

AUTOCOM=srcs/autocom/autocom.c\

MAKE=srcs/make/buff_editing.c\
	srcs/make/env.c\
	srcs/make/env2.c\
	srcs/make/process.c\
	srcs/make/term_make.c\
	srcs/make/term_make2.c\
	
PARSER=srcs/parser/parse.c\

READING=srcs/reading/reading.c\

SIGNAL=srcs/signal/signal.c\

TERM=srcs/term/term.c\

BUILTINS=srcs/builtins/cd/cd.c\
		srcs/builtins/echo/echo.c\
		srcs/builtins/env/env.c\
		srcs/builtins/setenv/setenv.c\
		srcs/builtins/unsetenv/unsetenv.c\

EXEC=srcs/exec/exec.c

SRC_SEARCH =$(ERROR) $(LINE_EDITING)  $(MAKE) $(PARSER) $(READING) $(SIGNAL) $(TERM) $(EXEC) $(BUILTINS)

SRC = $(wildcard $(SRC_SEARCH))

OBJ = $(SRC:.c=.o)

INCLUDES=includes

INCLUDES_LIB=libft/includes

EXTRA_FLAGS=-Wall -Wextra -Werror

LIB=libft

all:$(NAME)

$(NAME): $(OBJ) libft
	gcc $(OBJ) -o $@ -L $(LIB) -lft -lncurses

%.o: %.c
	gcc -c $< -o $@ $(EXTRA_FLAGS) -I $(INCLUDES) -I $(INCLUDES_LIB)

.PHONY: libft
libft:
	make -C libft

clean:
	make clean -C $(LIB)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIB)
	rm -rf $(NAME)

re: fclean all