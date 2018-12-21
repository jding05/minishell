NAME = minishell

# directories
SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft/

# compiler
CC = gcc
FLAGS = -Wall -Werror -Wextra
INC = -I ./include/ -I ./$(LIBFT_DIR)includes/
DEBUG = -g -fsanitize=address
# FLAGS += $(DEBUG)

# files
SRC_FILES	= $(notdir $(wildcard $(SRC_DIR)*.c))

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# colors
LIGHT_GREEN	=\x1b[32;01m
GREEN		=\033[1;0m\033[32m
WHITE		=\x1b[0m
YELLOW		=\033[33m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)compiling library ..."
	@make -C $(LIBFT_DIR)
	@$(CC) $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_DIR) -lft -o $(NAME) -lreadline
	@echo "$(WHITE)Binary $(LIGHT_GREEN)$(NAME) $(WHITE)created."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@
	@echo "$(YELLOW)Compiled: $(WHITE)$(notdir $<)"

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -rf $(NAME)

re: fclean all
