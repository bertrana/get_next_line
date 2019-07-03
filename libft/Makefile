# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjohns <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 22:07:57 by yjohns            #+#    #+#              #
#    Updated: 2018/12/03 22:43:55 by yjohns           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c

INC = *.h

OBJ = $(SRCS:%.c=%.o)

GFLAGS = -Wall -Wextra -Werror

.PHONE:	all clean fclean re

all: $(NAME)

$(NAME): 
	gcc $(GFLAGS) -I $(INC) -c $(SRCS)
	ar rc $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
