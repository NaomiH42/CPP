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
