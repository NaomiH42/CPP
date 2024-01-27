NAME = interface

SRCS =	main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OLD_FLAGS = -std=c++98
C++_FLAGS = c++ -g -Wall -Werror -Wextra ${OLD_FLAGS}

all:	${NAME}

${NAME}: ${SRCS}
	${C++_FLAGS} ${SRCS} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
