#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 18:05:28 by sadawi            #+#    #+#              #
#    Updated: 2019/11/06 14:33:17 by sadawi           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRCS = ft*.c

OBJS = *.o

all: $(NAME)

$(NAME): ft_printf.h
	gcc -c -Wall -Werror -Wextra $(SRCS)
	ar rc $(NAME) $(OBJS)

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
