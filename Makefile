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

SRCS =	main.c \
		ft_checker_similar.c \
		ft_fillit.c \
		ft_print_step.c \
		ft_simplify_back_count_square_in_sq.c \
		ft_struct_creator_delete_list.c

LIBFT = libft/

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Creating .o files. Please wait..."
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT) -lft
	@echo "All .o files successfully created."
	@echo "Fillit successfully created."

%.o: %.c
	@$(CC) $(FLAGS) -c $<

clean:
	@echo "Deleting all .o files. Please wait..."
	@rm -f $(OBJECTS)
	@make clean -C $(LIBFT)
	@echo "All .o files deleted."	

fclean: clean
	@echo "Deleting all .o files and fillit. Please wait..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "All .o files and fillit deleted."	

re: fclean all

.PHONY: re all clean fclean
