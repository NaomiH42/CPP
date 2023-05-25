# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 14:29:59 by ehasalu           #+#    #+#              #
#    Updated: 2023/05/25 12:37:02 by ehasalu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = point_in_triangle

SRCS =	main.cpp Fixed.cpp fixedConstr.cpp fixedOverl.cpp Point.cpp

OLD_FLAGS = -std=c++98
C++_FLAGS = g++ -Wall -Werror -Wextra ${OLD_FLAGS}

all:	${NAME}

${NAME}: ${SRCS}
	${C++_FLAGS} ${SRCS} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
