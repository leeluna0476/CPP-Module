NAME=sed
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror --std=c++98
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
