# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/17 08:40:28 by tettouat          #+#    #+#              #
#    Updated: 2015/11/25 15:05:11 by tettouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_script

LIB = ./libft/libft.a

CFLAG = -Wall -Wextra -Werror

SRCC = cmd.c date.c end.c opts_errors.c fill_opts.c find_path.c find_shell.c\
		get_mands.c get_opts.c io.c open.c ft_script.c shell.c child_signal.c\
		user_signal.c winch_signal.c signal.c tools.c term.c main.c

SRCO = $(SRCC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO) $(LIB)
	gcc $(SRCO) $(LIB) -o $(NAME) $(CFLAG)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(LIB):
	make -C libft/ fclean
	make -C libft

clean:
	rm -f $(SRCO)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
