# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 23:09:40 by tsekiguc          #+#    #+#              #
#    Updated: 2021/12/15 23:39:05 by tsekiguc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO			=	philo
SRCS			=	main.c
#					chopstick.c
OBJS_DIR		=	./objs
OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-I./include
LIB				=	-lpthread
RM				=	rm -f

.PHONY			:	all clean fclean re

vpath %.h include
vpath %.c srcs

all				:	$(PHILO)

$(PHILO)		:	$(OBJS)
					$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $@

$(OBJS_DIR)/%.o	:	%.c
					@[ -d $(OBJS_DIR) ]
					$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean			:
					$(RM) $(OBJS)

fclean			:
					$(RM) $(OBJS) $(PHILO) 

re				:	fclean all
