# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehasalu <ehasalu@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 14:29:55 by ehasalu           #+#    #+#              #
#    Updated: 2023/05/21 14:29:56 by ehasalu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence

SRCS =	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

FLAGS = -std=c++98
C++_FLAGS = g++ -Wall -Werror -Wextra ${FLAGS}

all:	${NAME}

${NAME}:
	${C++_FLAGS} ${SRCS} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
