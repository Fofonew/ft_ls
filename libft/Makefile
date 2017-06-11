# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriol <doriol@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 04:00:07 by doriol            #+#    #+#              #
#    Updated: 2017/05/03 18:20:27 by doriol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_isdigit.c\
	ft_atoi.c\
	ft_strcat.c\
	ft_strcmp.c\
	ft_strcpy.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_strncat.c\
	ft_strncmp.c\
	ft_strncpy.c\
	ft_strstr.c\
	ft_strlcat.c\
	ft_memset.c\
	ft_memcpy.c\
	ft_bzero.c\
	ft_memccpy.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memmove.c\
	ft_strchr.c\
	ft_strnstr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_strrchr.c\
	ft_putnbr_fd.c\
	ft_putendl_fd.c\
	ft_putstr_fd.c\
	ft_putchar_fd.c\
	ft_putnbr.c\
	ft_putendl.c\
	ft_putstr.c\
	ft_putchar.c\
	ft_itoa.c\
	ft_strsplit.c\
	ft_strtrim.c\
	ft_strjoin.c\
	ft_strsub.c\
	ft_strnequ.c\
	ft_strequ.c\
	ft_strmapi.c\
	ft_strmap.c\
	ft_striteri.c\
	ft_striter.c\
	ft_strclr.c\
	ft_strdel.c\
	ft_strnew.c\
	ft_memdel.c\
	ft_memalloc.c\
	ft_cleaner.c\
	ft_strrlen.c\
	ft_digitlen.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_str_is_alpha.c\
	ft_strcapitalize.c\
	get_next_line.c\

SRCS2 = ft_isalpha.o\
	ft_isalnum.o\
	ft_isascii.o\
	ft_isprint.o\
	ft_isdigit.o\
	ft_atoi.o\
	ft_strcat.o\
	ft_strcmp.o\
	ft_strcpy.o\
	ft_strdup.o\
	ft_strlen.o\
	ft_strncat.o\
	ft_strncmp.o\
	ft_strncpy.o\
	ft_strstr.o\
	ft_strlcat.o\
	ft_memset.o\
	ft_memcpy.o\
	ft_bzero.o\
	ft_memccpy.o\
	ft_memchr.o\
	ft_memcmp.o\
	ft_memmove.o\
	ft_strchr.o\
	ft_strnstr.o\
	ft_tolower.o\
	ft_toupper.o\
	ft_strrchr.o\
	ft_putnbr_fd.o\
	ft_putendl_fd.o\
	ft_putstr_fd.o\
	ft_putchar_fd.o\
	ft_putnbr.o\
	ft_putendl.o\
	ft_putstr.o\
	ft_putchar.o\
	ft_itoa.o\
	ft_strsplit.o\
	ft_strtrim.o\
	ft_strjoin.o\
	ft_strsub.o\
	ft_strnequ.o\
	ft_strequ.o\
	ft_strmapi.o\
	ft_strmap.o\
	ft_striteri.o\
	ft_striter.o\
	ft_strclr.o\
	ft_strdel.o\
	ft_strnew.o\
	ft_memdel.o\
	ft_memalloc.o\
	ft_cleaner.o\
	ft_strrlen.o\
	ft_digitlen.o\
	ft_lstnew.o\
	ft_lstdelone.o\
	ft_lstdel.o\
	ft_lstadd.o\
	ft_lstiter.o\
	ft_lstmap.o\
	ft_str_is_alpha.o\
	ft_strcapitalize.o\
	get_next_line.o\

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS) -I includes/
	@ar rc $(NAME) $(SRCS2)

clean:
	@rm -f $(SRCS2)

fclean: clean
	@rm -f $(NAME)

re: fclean all
