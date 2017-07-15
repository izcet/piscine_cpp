# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 15:27:10 by irhett            #+#    #+#              #
#    Updated: 2017/07/09 23:07:27 by irhett           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_retro
FAME		=	retro_ft

CXX			=	clang++
FLAGS		=	-Wall -Werror -Wextra -std=c++98

SRC_DIR		=	src
SRC_FILE	=	main.cpp \
				GameEntity.class.cpp \
				Player.class.cpp \
				Enemy.class.cpp \
				Game.cpp \
				Environment.cpp \
				Menu.cpp \
				Screen.cpp	\
				Missile.class.cpp
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		=	obj
OBJ_FILE	=	$(SRC_FILE:.cpp=.o)
OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILE))

INC			=	-I src


MINI_DIR	=	mini
MINI_FILE	=	main.cpp \
				Entity.class.cpp \
				World.class.cpp \
				Player.class.cpp \
				List.class.cpp \
				Enemy.class.cpp \
				Bullet.class.cpp 
MINIS		=	$(addprefix $(MINI_DIR)/, $(MINI_FILE))

MOB_DIR		=	mob
MOB_FILE	=	$(MINI_FILE:.cpp=.o)
MOBS		=	$(addprefix $(MOB_DIR)/, $(MOB_FILE))

INK			=	-I mini

.PHONY: re fclean clean all

all: $(NAME) $(FAME)

$(NAME): $(SRCS) | $(OBJS)
	$(CXX) $(INC) $(FLAGS) -l ncurses -l menu $(OBJS) -o $(NAME)

$(FAME): $(MINIS) | $(MOBS)
	$(CXX) $(INK) $(FLAGS) -l ncurses $(MOBS) -o $(FAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(INC) -c $^ $(FLAGS) -o $@

$(MOB_DIR)/%.o: $(MINI_DIR)/%.cpp | $(MOB_DIR)
	@$(CXX) $(INK) -c $^ $(FLAGS) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(MOB_DIR):
	@mkdir -p $(MOB_DIR)

clean:
	rm -rf $(MOB_DIR) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(FAME) 

re: fclean all
