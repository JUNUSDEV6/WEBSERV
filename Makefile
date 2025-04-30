
NAME = webserv

SRCS_DIR = ./
OBJS_DIR = .objs

SRCS = main.cpp

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(OPTIONS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re : fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re run