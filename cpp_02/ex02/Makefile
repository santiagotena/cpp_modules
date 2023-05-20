# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 23:31:23 by stena-he          #+#    #+#              #
#    Updated: 2023/05/20 11:22:17 by stena-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
NAME 	= fpnumber
CC 		= c++
CFLAGS 	= -Wextra -Wall -Werror -std=c++98
DEBUG 	= -g -fsanitize=address

# Clean
RM = rm -rf

# Source and object files
SRC =	Fixed.cpp \
		main.cpp
		
OBJ	=	$(SRC:.cpp=.o)

# Colors
GREEN	:= \x1b[32m
RESET	:= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DEBUG) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable <$(NAME)> compiled successfully.$(RESET)"

clean:
	@$(RM) $(OBJ)
	@echo "$(GREEN)Object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Removed executable.$(RESET)"
	
re: fclean all

.SILENT: $(OBJ)
.PHONY: all clean fclean re