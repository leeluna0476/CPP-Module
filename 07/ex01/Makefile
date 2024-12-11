.DEFAULT_GOAL = all

NAME=iter
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror --std=c++98 -MMD -MP
SRCS= \
	 main.cpp \

OBJS=$(SRCS:.cpp=.o)
DEPS=$(SRCS:.cpp=.d)
-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	$(LINK.cpp) $(OUTPUT_OPTION) $<

%.o: %.cpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

clean:
	rm -fr $(OBJS) $(DEPS)

fclean: clean
	rm -fr $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
