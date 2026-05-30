NAME = cub3d

SRC_PATH = ./src/
SRC_FILES = main.c

PARSE_PATH = ./src/parsing/
PARSE_FILES += flood_fill.c
PARSE_FILES += init_game.c
PARSE_FILES += parse_colors.c
PARSE_FILES += parse_file.c
PARSE_FILES += parse_map.c
PARSE_FILES += parse_texture.c
PARSE_FILES += validate_map.c

UTILS_PATH = ./src/utils/
UTILS_FILES = errors.c

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
SRC += $(addprefix $(PARSE_PATH), $(PARSE_FILES))
SRC += $(addprefix $(UTILS_PATH), $(UTILS_FILES))

OBJS_DIR = obj
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))

CFLAGS = -Wall -Werror -Wextra

LIB_PATH = ./libs/libft/
LIB_NAME = libft.a
LIB = $(LIB_PATH)$(LIB_NAME)

INC_PATH = ./includes/
INC	= -I$(INC_PATH)
INC	+= -I$(LIB_PATH)

RM = rm -rf

GREEN  := \033[0;32m
RED    := \033[0;31m
YELLOW := \033[1;33m
RESET  := \033[0m

all: $(LIB) $(NAME)

$(LIB): 
	@make -C $(LIB_PATH)

$(OBJS_DIR):
	@mkdir -p obj
	@echo "$(YELLOW)\n Objects directory created!\n$(RESET)"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIB) -o $(NAME)
	@echo "$(GREEN)\n Compilation completed!\n$(RESET)"

clean:
	@make clean -C $(LIB_PATH)
	@$(RM) $(OBJS)
	@echo "$(RED)\n Objects removed successfully!\n$(RESET)"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@$(RM) $(NAME) $(OBJS_DIR)
	@echo "$(RED)\n Program removed successfully!\n$(RESET)"

re: fclean all
		@echo "$(GREEN)\n Re-compile was successfull!\n$(RESET)"

.PHONY: all clean fclean re