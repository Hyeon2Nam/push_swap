# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyenam <hyeon@student.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 14:41:56 by riiringim         #+#    #+#              #
#    Updated: 2021/09/11 16:31:12 by hyenam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc
AR = ar rcs
RM = rm -rf

SRCS = ft_atoi.c \
	  ft_strlen.c \
	  ft_strlcpy.c \
	  ft_split.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all