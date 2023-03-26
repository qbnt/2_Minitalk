# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 18:34:28 by qbanet            #+#    #+#              #
#    Updated: 2023/03/26 17:16:35 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_CLIENT = src/client.c src/utile.c
SRCS_SERVER = src/server.c src/utile.c

LIBFT = libft/libft.a
LIBFT_DIR = libft
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

INCLUDES = -Iincludes -I$(LIBFT_DIR)/includes

OBJS_DIR = objs
OBJS_CLIENT = $(SRCS_CLIENT:%.c=$(OBJS_DIR)/%.o)
OBJS_SERVER = $(SRCS_SERVER:%.c=$(OBJS_DIR)/%.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@echo "$(YELLOW)Linking client...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT_FLAGS) -o $(NAME_CLIENT)
	@echo "$(GREEN)Client created!$(RESET)"

$(NAME_SERVER): $(OBJS_SERVER)
	@echo "$(YELLOW)Linking server...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT_FLAGS) -o $(NAME_SERVER)
	@echo "$(GREEN)Server created!$(RESET)"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(GREEN)Client and Server executables cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
