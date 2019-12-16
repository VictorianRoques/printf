CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

NAME = libftprintf.a
SRC = ft_printf.c ft_printf_buff.c ft_printf_parse.c

SRC_DIR = Src
LIB_DIRS = Libft
INCLUDE_DIRS = $(LIB_DIRS) Includes

IFLAGS = $(INCLUDE_DIRS:%=-I%)
OBJ_DIR = obj
OBJS := $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) -C libft
	@cp ./Libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

debug: CFLAGS += -g3
debug: all

clean:
	$(RM) $(OBJ_DIR)
	@$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean $(NAME) all

main:
	CC -ILibft main.c libftprintf.a

.PHONY: clean fclean re debug make