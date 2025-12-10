NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

MLX_URL		= git@github.com:42paris/minilibx-linux.git
MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# ft_printf includes libft
PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a
PRINTF_FLAGS = -L$(PRINTF_DIR) -lftprintf

INCLUDES	= -I includes -I $(MLX_DIR) -I $(PRINTF_DIR)

SRCS_DIR	= srcs
OBJS_DIR	= objs

# Source files will be added here
SRC_FILES	= main.c math_utils.c utils.c init.c events.c render.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.c=.o))

all: $(MLX) $(PRINTF) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(PRINTF_FLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning MiniLibX..."; \
		git clone $(MLX_URL) $(MLX_DIR); \
	fi
	@echo "Compiling MiniLibX..."
	@make -C $(MLX_DIR)

$(PRINTF):
	@if [ -d "$(PRINTF_DIR)" ]; then \
		echo "Compiling ft_printf..."; \
		make -C $(PRINTF_DIR); \
	else \
		echo "WARNING: $(PRINTF_DIR) not found. Skipping ft_printf compilation."; \
	fi

clean:
	rm -rf $(OBJS_DIR)
	@if [ -d "$(PRINTF_DIR)" ]; then make clean -C $(PRINTF_DIR); fi
	@if [ -d "$(MLX_DIR)" ]; then make clean -C $(MLX_DIR); fi

fclean: clean
	rm -f $(NAME)
	@if [ -d "$(PRINTF_DIR)" ]; then make fclean -C $(PRINTF_DIR); fi
	rm -rf $(MLX_DIR)
	
re: fclean all

.PHONY: all clean fclean re
