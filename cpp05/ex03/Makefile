# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayeap <ayeap@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/02 15:56:21 by ayeap             #+#    #+#              #
#    Updated: 2026/05/02 15:56:21 by ayeap            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

SRC_PATH = src
INC_PATH = inc
OBJ_PATH = obj

SRC = $(wildcard $(SRC_PATH)/*.cpp)
OBJ = $(SRC:$(SRC_PATH)/%.cpp=$(OBJ_PATH)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INC_PATH) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(INC_PATH)/*.hpp | $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(wildcard *_shrubbery)

re: fclean all

.PHONY: all clean fclean re