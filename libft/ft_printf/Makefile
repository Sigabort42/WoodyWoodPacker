#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/10 17:33:59 by elbenkri          #+#    #+#              #
#    Updated: 2018/02/02 16:51:04 by elbenkri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

HEADER	=	ft_printf.h

SRCS	=	ft_is_number.c \
			ft_itoa_base.c \
			ft_itoa_base_maj.c \
			ft_ltoa_base.c \
			ft_ltoa_base_maj.c \
			ft_lltoa_base.c \
			ft_lltoa_base_maj.c \
			ft_i_maxtoa_base.c \
			ft_i_maxtoa_base_maj.c \
			ft_ui_maxtoa_base.c \
			ft_ui_maxtoa_base_maj.c \
			ft_stock_flags.c \
			ft_type.c \
			ft_printf.c \
			ft_ltoa.c \
			ft_lltoa.c \
			ft_i_maxtoa.c \
			ft_ui_maxtoa.c \
			ft_print_buffer.c \
			ft_flags.c \
			ft_print_flags_buffer.c \
			ft_flags_stock.c \
			ft_wchar.c \
			ft_wstrlen.c \
			ft_conv_envoi_maj.c \
			ft_conv_envoi.c \
			ft_flags_largeur.c \
			ft_stock_buf_base.c \
			ft_stock_moins.c \
			ft_stock_plus.c \
			ft_flags_stock2.c \
			ft_verif_buf.c \
			ft_verif_address.c \
			ft_verif_flags_stock2_4.c \
			ft_split2_2.c \
			ft_split2_5.c \
			ft_free.c \
			ft_init_var.c \
			ft_return_printf2.c \

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[H\033[2J\033[32;5m[OK...]"

clean:
	@rm -rf $(OBJS)
	@echo "\033[H\033[2J\033[32;5m[OK...]"

fclean:	clean
	@rm -rf $(NAME)
	@echo "\033[H\033[2J\033[32;5m[OK...]"

re: fclean all