NAME=phonebook
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror
SRCS=phonebook.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

%.o : %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr phonebook

re: fclean
	make all

.PHONY: all clean fclean re
