NAME		=	minishell

# commands
CC			=	cc
CFLAGS		=	-g# -Wall -Wextra -Werror
RM			=	rm -rf
MAKEFLAGS	+=	--no-print-directory

# libft
LIBFT		=	libft
LIBFT_DIR	=	./$(LIBFT)
LIBFT_A     =	$(LIBFT_DIR)/$(LIBFT).a

# srcs
SRCS_DIR	=	./srcs
BUILTIN_DIR	=	$(SRCS_DIR)/builtin
LEXER_DIR	=	$(SRCS_DIR)/lexer
PARSER_DIR	=	$(SRCS_DIR)/parser
EXPAN_DIR	=	$(SRCS_DIR)/expansion
EXEC_DIR	=	$(SRCS_DIR)/execution
TYPE_DIR	=	$(SRCS_DIR)/type

SRCS_COMMON	=	$(wildcard $(SRCS_DIR)/*.c)
BUILTIN_SRCS=	$(wildcard $(BUILTIN_DIR)/*.c)
LEXER_SRCS	=	$(wildcard $(LEXER_DIR)/*.c)
PARSER_SRCS	=	$(wildcard $(PARSER_DIR)/*.c)
EXPAN_SRCS	=	$(wildcard $(EXPAN_DIR)/*.c)
EXEC_SRCS	=	$(wildcard $(EXEC_DIR)/*.c)
TYPE_SRCS	=	$(wildcard $(TYPE_DIR)/*.c)

SRCS		=	$(SRCS_COMMON) $(BUILTIN_SRCS) $(LEXER_SRCS) $(PARSER_SRCS) $(EXPAN_SRCS) $(EXEC_SRCS) $(TYPE_SRCS)

# object
OBJS	=	$(SRCS:.c=.o)

# includes
INCLUDES	=	-I ./includes -I $(LIBFT_DIR)/includes -I $(OS_DIR)/includes
LDFLAGS		=	-lreadline
# OS differences
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	OS_DIR		=	$(LIBFT_DIR)/mac
	INCLUDES	+=	-I/opt/homebrew/opt/readline/include
	LDFLAGS		+=	-L/opt/homebrew/opt/readline/lib
else
	OS_DIR		=	$(LIBFT_DIR)/linux
endif


# font color
RESET		=	\033[0m
BOLD		=	\033[1m
LIGHT_BLUE	=	\033[94m
YELLOW		=	\033[93m

# extra rule
TOTAL_FILES := $(words $(OBJS) $(SERVER_OBJS))
CURRENT_FILE := 0

define progress
	@CURRENT_PERCENT=$$(expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)); \
	printf "$(YELLOW)Progress: %3d%% (%d/%d)$(RESET)\r" $$CURRENT_PERCENT $(CURRENT_FILE) $(TOTAL_FILES); \
	$(eval CURRENT_FILE=$$(($(CURRENT_FILE)+1)))
endef

# rule
all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@echo "$(BOLD)$(LIGHT_BLUE)Compiling $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LIBFT_A) -o $(NAME) $(LDFLAGS)
	@echo "$(BOLD)$(LIGHT_BLUE)$(NAME) created successfully!$(RESET)"

$(LIBFT_A):
	@echo "$(BOLD)$(LIGHT_BLUE)Compiling $(LIBFT)...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(eval CURRENT_FILE=$(shell expr $(CURRENT_FILE) + 1))
	@CURRENT_PERCENT=$$(expr $(CURRENT_FILE) \* 100 / $(TOTAL_FILES)); \
	printf "$(YELLOW)Progress: %3d%% (%d/%d)$(RESET)\r" $$CURRENT_PERCENT $(CURRENT_FILE) $(TOTAL_FILES); \
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(BOLD)$(LIGHT_BLUE)Cleaning objects...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)
	@echo "$(BOLD)$(LIGHT_BLUE)Objects cleaned!$(RESET)"

fclean:
	@echo "$(BOLD)$(LIGHT_BLUE)Full clean...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(OBJS) $(NAME)
	@echo "$(BOLD)$(LIGHT_BLUE)Full clean complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re

run: $(NAME)
	./$(NAME)

val: $(NAME)
	valgrind --leak-check=full ./$(NAME)

test: $(NAME)
	./$(NAME) 2>/dev/null
