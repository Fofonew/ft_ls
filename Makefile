# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriol <doriol@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 04:00:07 by doriol            #+#    #+#              #
#    Updated: 2017/11/22 10:33:29 by fofow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = ./srcs/ft_ls.c\
	   ./srcs/check_option.c\
	   ./srcs/display.c\
	   ./srcs/sort.c\
	   ./srcs/set.c\
	   ./srcs/display2.c\

SRCS2 = ft_ls.o\
		check_option.o\
		display.o\
		sort.o\
		set.o\
		display2.o\

all: $(NAME)

$(NAME):
	@make -C ft_printf/ fclean && name -C ft_printf
	@make -C libft/ fclean && make -C libft/
	@gcc -Wall -Wextra -Werror -I libft/includes/ -I ft_printf/includes/ -c $(SRCS)
	@gcc -o $(NAME) $(SRCS2) libft/libft.a ft_printf/ft_printf.a -I ./srcs/ls.h
	@mkdir obj
	@mv *.o obj/
	@echo "\033[32mft_ls compiled [ ✔ ]"

clean:
	@rm -rf obj/
	@make -C libft/ fclean
	@make -C ft_printf/ fclean
	@echo "\033[32mft_ls cleaned [ ✔ ]"

fclean: clean
	@rm -f $(NAME)

re: fclean all
