# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 23:09:40 by tsekiguc          #+#    #+#              #
#    Updated: 2021/12/27 18:19:11 by tsekiguc         ###   ########.fr        #
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
					ft_int_check.c\
					ft_isdigit.c\
					ft_isspace.c\
					ft_strlen.c\
					ft_putendl_fd.c\
					get_fork.c\
					get_status.c\
					monitoring.c\
					monitor_init.c\
					mutex_destroy.c\
					mutex_init.c\
					now_eating.c\
					now_sleeping.c\
					philo_action.c\
					philo_atoi.c\
					philos_init.c\
					philosopher.c\
					put_fork.c\
					put_timestamp.c\
					set_dead_time.c\
					set_status.c\
					stomach_check.c
OBJS_DIR		=	./objs
OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
#CFLAGS			+=	 -g -fsanitize=thread -O1
INCLUDE			=	-I./include
LIB				=	-lpthread
RM				=	rm -f

.PHONY			:	all clean fclean re

vpath %.h include
vpath %.c srcs

all				:	$(PHILO)

$(PHILO)		:	$(OBJS)
					$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $@

$(OBJS_DIR)/%.o	:	%.c philo.h
					@[ -d $(OBJS_DIR) ]
					$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean			:
					$(RM) $(OBJS)

fclean			:
					$(RM) $(OBJS) $(PHILO) 

re				:	fclean all
