# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 12:04:16 by qbanet            #+#    #+#              #
#    Updated: 2023/03/23 17:16:58 by qbanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = -crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAG = -rf

INCLUDES = -I./includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = 	ft_atoi.c	\
	ft_bzero.c	\
	ft_calloc.c	\
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_isprint.c	\
	ft_itoa.c	\
	ft_lstadd_back.c	\
	ft_lstadd_front.c	\
	ft_lstclear.c	\
	ft_lstdelone.c	\
	ft_lstiter.c	\
	ft_lstlast.c	\
	ft_lstmap.c	\
	ft_lstnew.c	\
	ft_lstsize.c	\
	ft_memchr.c	\
	ft_memcmp.c	\
	ft_memcpy.c	\
	ft_memmove.c	\
	ft_memset.c	\
	ft_printf_utils_adr.c	\
	ft_printf_utils_hexa.c	\
	ft_printf_utils_unsign.c	\
	ft_printf_utils.c	\
	ft_printf.c	\
	ft_putchar_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_putstr_fd.c	\
	ft_split.c	\
	ft_strchr.c	\
	ft_strdup.c	\
	ft_striteri.c	\
	ft_strjoin.c	\
	ft_strlcat.c	\
	ft_strlcpy.c	\
	ft_strlen.c	\
	ft_strmapi.c	\
	ft_strncmp.c	\
	ft_strnstr.c	\
	ft_strrchr.c	\
	ft_strtrim.c	\
	ft_substr.c	\
	ft_tolower.c	\
	ft_toupper.c	\
	get_next_line_utils.c	\
	get_next_line.c

SRC = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all : $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling:$(RESET) $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "$(GREEN)libft.a created!$(RESET)"

clean :
	@$(RM) $(RMFLAG) $(OBJ_DIR)
	@echo "$(YELLOW)Object files removed!$(RESET)"

fclean : clean
	@$(RM) $(RMFLAG) $(NAME)
	@echo "$(YELLOW)libft.a removed!$(RESET)"

re : fclean all

.PHONY: all clean fclean re
