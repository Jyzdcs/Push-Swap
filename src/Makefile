CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = main.c \
      stack_init.c \
      stack_methods1.c \
      stack_methods2.c \
      cheapest_handler.c \
      bring_node.c \
      sort.c \
      parse.c \
      utils.c

OBJ = $(SRC:.c=.o)

LIBFT = ../libft/libft.a
FTPRINTF = ../ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(FTPRINTF)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#test2:				$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-100 -n 2))
#					./push_swap $(ARG) | ./checker_linux $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l

#test3:				$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-100 -n 3))
#					./push_swap $(ARG) | ./checker_linux $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l

#test5:				$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
#					./push_swap $(ARG) | ./checker_linux $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l

#test100:			$(NAME)
#					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
#					./push_swap $(ARG) | ./checker_linux $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l

#test500:			$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
#					./push_swap $(ARG) | ./checker_linux $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l

#test1000:			$(NAME)	
#					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
#					./push_swap $(ARG) | ./checker_linux $(ARG)
#					@echo -n "Instructions: "
#					@./push_swap $(ARG) | wc -l
