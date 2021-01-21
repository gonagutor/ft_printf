# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 14:51:57 by gaguado-          #+#    #+#              #
#    Updated: 2021/01/21 17:43:54 by gaguado-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc
INCLUDES =		includes
LIBFT =			libft
FLAGS =			-Wall -Wextra -Werror -I.$(INCLUDES) $(LIBFT)/libft.h -c
OBJ_DIR =		objs
SRC_DIR =		srcs
NAME =			libftprintf.a

FILENAMES =		ft_printf.c

OBJS =			$(FILENAMES:%.c=%.o)
FILES =			$(addprefix $(SRC_DIR)/, $(FILENAMES))

$(NAME): $(OBJS)
	ar rcs $(NAME) ./$(LIBFT)/libft.a $(OBJS)

$(OBJS): $(FILES)
	$(MAKE) -C ./$(LIBFT)
	$(CC) $(FLAGS) $(FILES)


all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./$(LIBFT)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./$(LIBFT)

re: fclean all

.PHONY: all clean fclean re so
