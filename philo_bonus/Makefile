# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2023/03/22 19:25:51 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

SDIR		=	sources/

SRCS		=	$(SDIR)/philo_bonus.c \
				$(SDIR)/philo_process.c \
				$(SDIR)/philo_utils.c \
				$(SDIR)/philo_utils_2.c \
				$(SDIR)/philo_run.c \
				$(SDIR)/philo_set.c \

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -Iincludes -pthread

SFLAGS      =   -g3 -fsanitize=thread

RM			=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
#${NAME}: ${OBJS}
#	 @${CC} ${CFLAGS} ${SFLAGS} ${OBJS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all philo clean fclean re philo_bonus
