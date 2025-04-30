EXEC = webserv

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp\
       parsing.cpp\
       Config.cpp\
       Server.cpp\
       Location.cpp\

OBJS = $(SRCS:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(EXEC)

re : fclean all

.PHONY: all clean fclean re
