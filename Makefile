# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaguado- <gaguado-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 14:51:57 by gaguado-          #+#    #+#              #
#    Updated: 2021/02/17 14:27:17 by gaguado-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			gcc
INCLUDES =		includes
LIBFT =			libft
FLAGS =			-Wall -Wextra -Werror -I./$(INCLUDES) -c
OBJ_DIR =		objs
SRC_DIR =		srcs
NAME =			libftprintf.a

FILENAMES =		ft_printf.c ft_cflag.c ft_num_utils.c ft_flag_utils.c

OBJS =			$(FILENAMES:%.c=%.o)
FILES =			$(addprefix $(SRC_DIR)/, $(FILENAMES))

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(FILES)
	$(MAKE) -C ./$(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
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
