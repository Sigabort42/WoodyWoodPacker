# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elbenkri <elbenkri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 01:21:09 by elbenkri          #+#    #+#              #
#    Updated: 2020/12/27 01:21:11 by elbenkri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	woody_woodpacker

CC	=	/usr/bin/clang

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c \
		woody.c \
		inject.c \

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)
	@echo "\033[H\033[2J\033[32mBinary woody_woodpacker [\033[32;5mCreated\033[0m\033[32\
m]"

clean:
	@make -C ./libft clean
	@/bin/rm -rf $(OBJS)
	@echo "\033[H\033[2J\033[32mall .o [\033[32;5mCleared\033[0m\033[32m]"

fclean:	clean
	@make -C ./libft fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[H\033[2J\033[32mBinary woody_woodpacker [\033[32;5mCleared\033[0m\
\033[32m]"

re:	fclean all
