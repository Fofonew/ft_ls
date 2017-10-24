# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriol <doriol@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 04:00:07 by doriol            #+#    #+#              #
#    Updated: 2017/10/24 16:30:14 by doriol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = ./srcs/ft_ls.c\
	   ./srcs/check_option.c\
	   ./srcs/display.c\
	   ./srcs/sort.c\

SRCS2 = ft_ls.o\
		check_option.o\
		display.o\
		sort.o\

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -I libft/includes/ -c $(SRCS)
	@gcc -o $(NAME) $(SRCS2) libft/libft.a -I ./srcs/ls.h
	@mkdir obj
	@mv *.o obj/
	@echo "\033[32mft_ls compiled without flag !!! [ ✔ ]"

clean:
	@rm -rf obj/
	@make -C libft/ fclean
	@echo "\033[32mft_ls cleaned [ ✔ ]"

fclean: clean
	@rm -f $(NAME)

re: fclean all
