# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 23:09:40 by tsekiguc          #+#    #+#              #
#    Updated: 2021/12/22 11:32:40 by tsekiguc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO			=	philo
SRCS			=	main.c\
					get_fork.c\
					drop_fork.c\
					my_error.c\
					philosopher.c\
					set_status.c\
					get_status.c\
					put_timestamp.c\
					argv_atoi.c\
					fork_init.c\
					philos_init.c\
					set_dead_time.c\
					get_dead_time.c\
					monitoring.c\
					monitor_init.c\
					fork_destroy.c\
					philos_destroy.c\
					do_pthread_create.c\
					write_fork_array.c\
					erase_fork_array.c
OBJS_DIR		=	./objs
OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-fsanitize=thread -O1
CFLAGS			+=	-g
INCLUDE			=	-I./include
LIB				=	-lpthread -Llibft -lft
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
