# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehasalu <ehasalu@42prague.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 14:29:59 by ehasalu           #+#    #+#              #
#    Updated: 2023/10/13 11:58:51 by ehasalu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Mutant

SRCS =	main.cpp

OLD_FLAGS = -std=c++98
C++_FLAGS = c++ -Wall -Werror -Wextra ${OLD_FLAGS}

all:	${NAME}

${NAME}: ${SRCS}
	${C++_FLAGS} ${SRCS} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
