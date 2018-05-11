# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshiling <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/02 13:01:36 by sshiling          #+#    #+#              #
#    Updated: 2017/10/11 23:20:04 by sshiling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror

SRC_NAME = ft_fillit.c\
		ft_print_step.c\
		ft_checker_similar.c\
		ft_simplify_back_count_square_in_sq.c\
		ft_struct_creator_delete_list.c\
		main.c	

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
INC = -Iincludes/ -I$(LIB_DIR)includes/

LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR) --silent
	@echo "##### Lib created #####"
	gcc -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft
	@echo "##### Compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	@echo "##### Linking" [ $@ ] " #####"
	gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re
