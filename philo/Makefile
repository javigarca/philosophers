# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2023/03/22 18:05:30 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SDIR		=	sources/

SRCS		=	$(SDIR)/philo.c \
				$(SDIR)/philo_actions.c \
				$(SDIR)/philo_data.c \
				$(SDIR)/philo_init.c \
				$(SDIR)/philo_threads.c \
				$(SDIR)/philo_utils.c \

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -Iincludes -pthread

SFLAGS		=	-g3 -fsanitize=thread

RM			=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
#	@${CC} ${CFLAGS} ${SFLAGS} ${OBJS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all philo clean fclean re philo
