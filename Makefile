# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 23:09:40 by tsekiguc          #+#    #+#              #
#    Updated: 2021/12/26 22:38:16 by tsekiguc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO			=	philo
SRCS			=	main.c\
					add_eat_count.c\
					argv_atoi.c\
					dead_or_alive.c\
					do_pthread_create.c\
					do_pthread_join.c\
					drop_fork.c\
					fork_destroy.c\
					fork_init.c\
					get_fork.c\
					get_status.c\
					lock_destroy.c\
					lock_init.c\
					monitor_init.c\
					monitoring.c\
					now_eating.c\
					now_sleeping.c\
					off_fork_flag.c\
					on_fork_flag.c\
					philos_init.c\
					philosopher.c\
					put_fork.c\
					put_timestamp.c\
					set_dead_time.c\
					set_status.c
OBJS_DIR		=	./objs
OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
#CFLAGS			+=	 -g -fsanitize=thread -O1
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
