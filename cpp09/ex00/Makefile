# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 02:01:29 by ayeap             #+#    #+#              #
#    Updated: 2026/05/14 02:01:29 by ayeap            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bitcoin

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
INC = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re