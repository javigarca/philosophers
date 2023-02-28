# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2023/02/28 21:43:35 by javi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

SDIR		=	sources/

SRCS		=	$(SDIR)/philo_bonus.c \
				$(SDIR)/philo_data.c \
				$(SDIR)/philo_utils.c \
				$(SDIR)/philo_init.c \
				$(SDIR)/philo_academia.c \
				$(SDIR)/philo_actions.c \

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -Iincludes -g3 -pthread -fsanitize=address

RM			=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all philo clean fclean re philo_bonus
