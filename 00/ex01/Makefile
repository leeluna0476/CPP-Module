NAME=phonebook
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror --std=c++98
SRCS=phonebook.cpp phonebook_private.cpp main.cpp contact.cpp
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
