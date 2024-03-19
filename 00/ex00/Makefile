NAME=megaphone
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror --std=c++98
SRCS=megaphone.cpp
OBJS=$(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr megaphone

re: fclean
	make all

.PHONY: all clean fclean re
