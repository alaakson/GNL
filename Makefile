NAME = get_next_line.a

CC = cc
AR = ar
SRC = get_next_line.c \
      get_next_line_utils.c

OFILES = $(SRC%.c%=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OFILES)
	$(AR) -rcs	$(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OFILES) 

fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
