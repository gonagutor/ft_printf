# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 14:51:57 by gaguado-          #+#    #+#              #
#    Updated: 2021/01/21 17:45:18 by gaguado-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SONAME = libft.so
CC = gcc
SOURCEDIR = srcs
FLAGS = -Wall -Werror -Wextra -I. -c
FILES = $(SOURCEDIR)/ft_atoi.c \
		$(SOURCEDIR)/ft_bzero.c \
		$(SOURCEDIR)/ft_calloc.c \
		$(SOURCEDIR)/ft_isalnum.c \
		$(SOURCEDIR)/ft_isalpha.c \
		$(SOURCEDIR)/ft_isascii.c \
		$(SOURCEDIR)/ft_isdigit.c \
		$(SOURCEDIR)/ft_isprint.c \
		$(SOURCEDIR)/ft_itoa.c \
		$(SOURCEDIR)/ft_memccpy.c \
		$(SOURCEDIR)/ft_memchr.c \
		$(SOURCEDIR)/ft_memcmp.c \
		$(SOURCEDIR)/ft_memcpy.c \
		$(SOURCEDIR)/ft_memmove.c \
		$(SOURCEDIR)/ft_memset.c \
		$(SOURCEDIR)/ft_putchar_fd.c \
		$(SOURCEDIR)/ft_putendl_fd.c \
		$(SOURCEDIR)/ft_putnbr_fd.c \
		$(SOURCEDIR)/ft_putstr_fd.c \
		$(SOURCEDIR)/ft_split.c \
		$(SOURCEDIR)/ft_strchr.c \
		$(SOURCEDIR)/ft_strdup.c \
		$(SOURCEDIR)/ft_strjoin.c \
		$(SOURCEDIR)/ft_strlcat.c \
		$(SOURCEDIR)/ft_strlcpy.c \
		$(SOURCEDIR)/ft_strlen.c \
		$(SOURCEDIR)/ft_strmapi.c \
		$(SOURCEDIR)/ft_strncmp.c \
		$(SOURCEDIR)/ft_strnstr.c \
		$(SOURCEDIR)/ft_strrchr.c \
		$(SOURCEDIR)/ft_strtrim.c \
		$(SOURCEDIR)/ft_substr.c \
		$(SOURCEDIR)/ft_tolower.c \
		$(SOURCEDIR)/ft_toupper.c \
		$(SOURCEDIR)/ft_lstnew.c \
		$(SOURCEDIR)/ft_lstadd_front.c \
		$(SOURCEDIR)/ft_lstsize.c \
		$(SOURCEDIR)/ft_lstlast.c \
		$(SOURCEDIR)/ft_lstadd_back.c \
		$(SOURCEDIR)/ft_lstdelone.c \
		$(SOURCEDIR)/ft_lstclear.c \
		$(SOURCEDIR)/ft_lstiter.c \
		$(SOURCEDIR)/ft_lstmap.c

OBJ =	$(FILES:$(SOURCEDIR)/%.c=%.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(FLAGS) $(FILES)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(SONAME)

re: fclean all

so:
	gcc -shared -o $(SONAME) -fPIC $(FILES)

.PHONY: all clean fclean re so