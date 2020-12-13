# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhayward <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 13:44:06 by lhayward          #+#    #+#              #
#    Updated: 2020/12/08 16:44:06 by lhayward         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS				= ft_printf.c\
					  obnul.c\
					  flagi.c\
					  print_int.c\
					  print_str.c\
					  print_sym.c\
					  print.point.c\
					  print_uint_hex.c\
					  print_proc.c\
					  conver.c\
					  itoiki.c\
					  ft_strchr.c\
					  conver_bonus_plus.c\
					  bonus_printf_plus.c\
					  convert_bon_hex.c\
					  print_hex_bonus.c\
					  conver_int.c\
					  con_flag_float.c\
					  itoa_float.c\
					  print_float.c\
					  prebor.c\
					  print_float_plus.c\
					  con_float_plus.c
					 

OBJC		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJC}
			ar rc libftprintf.a ${OBJC}

all:		${NAME}

clean:		
			${RM} ${OBJC}

fclean:		clean
			${RM} ${NAME}

re:			fclean	all

bonus: fclean all

.PHONY:		all clean fclean re

