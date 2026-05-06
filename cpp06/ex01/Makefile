# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 02:44:04 by ayeap             #+#    #+#              #
#    Updated: 2026/05/05 02:44:04 by ayeap            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serialize

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
INC = $(wildcard *.hpp)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re