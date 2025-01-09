.DEFAULT_GOAL = all

NAME=PmergeMe
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror --std=c++98
CPPFLAGS=-MMD -MP -MF $(DEPS_DIR)/$*.d
SRCS= \
	 main.cpp \
	 PmergeMe.cpp \

RM=rm -fr

OBJS_DIR=.objs
OBJS=$(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

DEPS_DIR=.deps
DEPS=$(addprefix $(DEPS_DIR)/, $(SRCS:.cpp=.d))
-include $(DEPS)

ifeq ($(MAKECMDGOALS),deque)
	CPPFLAGS+=-D DEQUE
endif

ifeq ($(MAKECMDGOALS),debug)
	CXXFLAGS+=-g3 -fsanitize=address
endif

ifeq ($(MAKECMDGOALS),debug deque)
	CPPFLAGS+=-D DEQUE
	CXXFLAGS+=-g3 -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(LINK.cpp) $(OUTPUT_OPTION) $(OBJS)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR) $(DEPS_DIR)
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(DEPS_DIR):
	mkdir -p $(DEPS_DIR)

deque: all
debug: all
debug deque: all

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) $(OBJS_DIR) $(DEPS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
