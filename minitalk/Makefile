# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 18:34:28 by qbanet            #+#    #+#              #
#    Updated: 2023/03/25 14:59:26 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

SRCDIR = src
INCDIR = includes
LIBDIR = libft
OBJDIR = obj

SRC_CLIENT = $(SRCDIR)/client.c $(SRCDIR)/utile.c
SRC_SERVER = $(SRCDIR)/server.c $(SRCDIR)/utile.c

OBJDIR_CLIENT = $(OBJDIR)/client
OBJDIR_SERVER = $(OBJDIR)/server
OBJDIR_LIBFT = $(OBJDIR)/libft

OBJ_CLIENT = $(addprefix $(OBJDIR_CLIENT)/,$(notdir $(SRC_CLIENT:.c=.o)))
OBJ_SERVER = $(addprefix $(OBJDIR_SERVER)/,$(notdir $(SRC_SERVER:.c=.o)))
LIB_OBJ = $(addprefix $(OBJDIR_LIBFT)/,$(notdir $(LIB_SRC:.c=.o)))

LIB_MAKEFILE = $(LIBDIR)/Makefile
LIB_INC = $(LIBDIR)/includes/libft.h
LIB_SRC = $(wildcard $(LIBDIR)/src/*.c)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(INCDIR) -I$(LIBDIR)/includes
LDFLAGS = -L$(LIBDIR) -lft

# Define colors
BLUE	= \033[0;34m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
RESET	= \033[0m

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIB_OBJ) $(LIB_MAKEFILE)
	@$(MAKE) -C $(LIBDIR)
	@echo "$(GREEN)Compiling $@...$(RESET)"
	@$(CC) $(LDFLAGS) $^ -o $@
	@echo "$(YELLOW)$@ has been successfully compiled!$(RESET)"

$(NAME_SERVER): $(OBJ_SERVER) $(LIB_OBJ) $(LIB_MAKEFILE)
	@$(MAKE) -C $(LIBDIR)
	@echo "$(GREEN)Compiling $@...$(RESET)"
	@$(CC) $(LDFLAGS) $^ -o $@
	@echo "$(YELLOW)$@ has been successfully compiled!$(RESET)"

$(OBJDIR_CLIENT)/%.o: $(SRCDIR)/%.c $(INCDIR)/minitalk.h | $(OBJDIR_CLIENT)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJDIR_SERVER)/%.o: $(SRCDIR)/%.c $(INCDIR)/minitalk.h | $(OBJDIR_SERVER)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJDIR_LIBFT)/%.o: $(LIBDIR)/src/%.c $(LIB_INC) $(LIB_MAKEFILE) | $(OBJDIR_LIBFT)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJDIR_CLIENT):
	@mkdir -p $@

$(OBJDIR_SERVER):
	@mkdir -p $@

$(OBJDIR_LIBFT):
	@mkdir -p $@

clean:
	@$(MAKE) -C $(LIBDIR) clean
	@$(RM) -r $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBDIR) fclean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(YELLOW)$(NAME_CLIENT) and $(NAME_SERVER) have been removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
