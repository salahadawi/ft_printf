#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 18:05:28 by sadawi            #+#    #+#              #
#    Updated: 2019/12/10 17:29:22 by sadawi           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRCS = ft_printf.c handle_datatypes.c handle_flags.c handle_format_flags.c

OBJS = *.o

FLAGS = -Wall -Werror -Wextra

RUN_LIB = make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME): 
	@$(RUN_LIB)
	@gcc $(FLAGS) -c $(SRCS)
	@cp libft/libft.a libftprintf.a
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(OBJS)
	@make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
