# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inigo <inigo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 18:14:19 by inigo             #+#    #+#              #
#    Updated: 2022/11/01 18:19:53 by inigo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) 

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re 