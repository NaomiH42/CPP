# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehasalu <ehasalu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 14:29:59 by ehasalu           #+#    #+#              #
#    Updated: 2024/01/18 13:49:51 by ehasalu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS =	main.cpp PmergeMe.cpp

OLD_FLAGS = -std=c++98
C++_FLAGS = c++ -Wall -Werror -Wextra ${OLD_FLAGS} -g

all:	${NAME}

${NAME}: ${SRCS}
	${C++_FLAGS} ${SRCS} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
