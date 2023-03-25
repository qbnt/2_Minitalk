# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 18:34:28 by qbanet            #+#    #+#              #
#    Updated: 2023/03/23 11:08:22 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = includes
SRC_DIR = src
SRC_CLIENT = $(SRC_DIR)/client.c
SRC_SERVER = $(SRC_DIR)/server.c
SRC_UTILS = $(SRC_DIR)/utils.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_UTILS = $(SRC_UTILS:.c=.o)

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m # No Color

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS)
	@echo "$(YELLOW)Compiling client...$(NC)"
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) -o $(NAME_CLIENT)
	@echo "$(GREEN)Client compiled successfully!$(NC)"

$(NAME_SERVER): $(OBJ_SERVER) $(OBJ_UTILS)
	@echo "$(YELLOW)Compiling server...$(NC)"
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_UTILS) -o $(NAME_SERVER)
	@echo "$(GREEN)Server compiled successfully!$(NC)"

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_UTILS)

fclean: clean
	@echo "$(RED)Cleaning executables...$(NC)"
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
