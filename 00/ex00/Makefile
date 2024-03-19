NAME=megaphone
CC=c++
CFLAGS=-Wall -Wextra -Werror
SRCS=megaphone.cpp
OBJS=$(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr megaphone

re: fclean
	make all

.PHONY: all clean fclean re
