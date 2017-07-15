# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 15:27:10 by irhett            #+#    #+#              #
#    Updated: 2017/07/04 16:15:18 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

CXX			=	g++
FLAGS		=	-Wall -Werror -Wextra

SRC_DIR		=	src
SRC_FILE	=	megaphone.cpp
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

.PHONY: re fclean clean all noise

all: $(NAME)

$(NAME): $(SRCS) | $(OBJS)
	    $(CXX) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) -c $^ $(FLAGS) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

noise:
	@cat .mega
