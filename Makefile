# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 09:36:31 by hyenam            #+#    #+#              #
#    Updated: 2021/08/26 15:53:28 by hyenam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC := gcc
RM := rm -rf
CFLAGS := -Wall -Werror -Wextra
INCLUDE = -I. -I./libft
LIBS = -Llibft -lft
SRCS = 	./main.c ./utils.c ./stack_control.c ./stack_util.c \
		./duplicate_checker.c ./sort.c \
		./command/command_p.c ./command/command_r.c \
		./command/command_s.c ./command/command_rr.c

OBJS = $(SRCS:.c=.o)

LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

all : $(NAME)

.PHONY : all clean fclean re

$(NAME): $(OBJS)
		make -C $(LIB_DIR) bonus
		gcc $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDE) $(LIBS)

clean:
	$(RM) $(OBJS)
	make -C $(LIB_DIR) clean

fclean : clean
	$(RM) $(NAME)
	make -C $(LIB_DIR) fclean

re : fclean all
