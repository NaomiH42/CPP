NAME = myawesomephonebook

SRCS =	myawesomephonebook.cpp Phonebook.cpp

FLAGS = -std=c++98
C++_FLAGS = c++ -Wall -Werror -Wextra ${FLAGS}

all:	${NAME}

${NAME}:
	${C++_FLAGS} ${SRCS} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re
