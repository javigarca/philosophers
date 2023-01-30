# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:38:08 by javigarc          #+#    #+#              #
#    Updated: 2023/01/30 16:56:09 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
NAME_BONUS	=	philo_bonus

SRCS		=	$(wildcard philo/*.c) 
BONUS_SRCS	=	$(wildcard philo_bonus/*.c) 

OBJS		=	${SRCS:.c=.o}
BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -Iincludes -g3 -pthread -fsanitize=address

RM			=	rm -rf

all: ${NAME} ${NAME_BONUS}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${NAME_BONUS}: ${BONUS_OBJS}
	@${CC} ${CFLAGS} ${BONUS_OBJS} -o ${BONUS_NAME}

clean:
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all philo philo_bonus clean fclean re
