NAME        = cub3d
SRC_PATH    = ./src/
SRC_FILES   = main.c init.c raycast.c
SRC         = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS_DIR    = obj
OBJS        = $(patsubst $(SRC_PATH)%.c, $(OBJS_DIR)/%.o, $(SRC))

CFLAGS      = -Wall -Werror -Wextra

# Libft
LIB_PATH    = ./libs/libft/
LIB_NAME    = libft.a
LIB         = $(LIB_PATH)$(LIB_NAME)

# MiniLibX
MLX_PATH    = ./libs/minilibx-linux/
MLX_NAME    = libmlx.a
MLX         = $(MLX_PATH)$(MLX_NAME)
MLX_FLAGS   = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

# Includes
INC         = -I./includes/
INC         += -I$(LIB_PATH)
INC         += -I$(MLX_PATH)

RM          = rm -rf
GREEN       := \033[0;32m
RED         := \033[0;31m
YELLOW      := \033[1;33m
RESET       := \033[0m

all: $(LIB) $(MLX) $(NAME)

$(LIB):
	@make -C $(LIB_PATH)

$(MLX):
	@make -C $(MLX_PATH)

$(OBJS_DIR)/%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)\n Compilation completed!\n$(RESET)"

clean:
	@make clean -C $(LIB_PATH)
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)\n Objects removed successfully!\n$(RESET)"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@$(RM) $(NAME)
	@echo "$(RED)\n Program removed successfully!\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
