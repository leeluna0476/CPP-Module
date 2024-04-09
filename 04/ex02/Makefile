.DEFAULT_GOAL = all

NAME=abstract
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror --std=c++98 -MMD -MP
SRCS= \
	 main.cpp \
	 Cat.cpp \
	 Dog.cpp \
	 Animal.cpp \
	 WrongCat.cpp \
	 WrongAnimal.cpp \
	 Brain.cpp
OBJS=$(SRCS:.cpp=.o)
DEPS=$(SRCS:.cpp=.d)
-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -fr $(OBJS) $(DEPS)

fclean: clean
	rm -fr $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
