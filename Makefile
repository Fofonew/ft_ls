# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriol <doriol@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 04:00:07 by doriol            #+#    #+#              #
#    Updated: 2017/06/12 01:13:57 by fofow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = ./srcs/ft_ls.c\

SRCS2 = ft_ls.o\

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -I libft/includes/ -c $(SRCS)
	@gcc -o $(NAME) $(SRCS2) libft/libft.a
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
