# **************************************************************************** #
# VARIABLES

NAME				:= cub3D

MACHINE				:= $(shell uname -s)

CC					:= gcc
CFLAGS				:= -Wall -Wextra -Werror

RM					:= rm -rf

LIBFT				:= libft
LIBFT_A				:= ./libft/libft.a

GNL					:= gnl
GNL_A				:= ./gnl/gnl.a

MLX_DIR				:= mlx
MLX_A				:= ./mlx/libmlx.a

# **************************************************************************** #
# COLORS

GREEN				:= \033[0;92m
YELLOW				:= \033[0;93m
BLUE				:= \033[0;94m
END_COLOR			:= \033[0;39m

# **************************************************************************** #
# RULES

all : $(NAME)

$(NAME):
ifeq ($(MACHINE), Darwin)
	@echo "$(BLUE)make $(MLX_DIR)$(END_COLOR)"
	make -C $(MLX_DIR)
	@echo "$(BLUE)make $(LIBFT) $(END_COLOR)"
	make -C $(LIBFT)
	@echo "$(BLUE)make $(GNL) $(END_COLOR)"
	make -C $(GNL)
	$(CC) $(CFLAGS) -I . $(MLX_A) $(LIBFT_A) $(GNL_A) -framework OpenGL -framework AppKit main.c -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled :)$(END_COLOR)"
# -C	:	make option that tells make to change directory before execution.
else
	@echo "$(BLUE)make $(MLX_DIR)$(END_COLOR)"
	make -C $(MLX_DIR)
	@echo "$(BLUE)make $(LIBFT) $(END_COLOR)"
	make -C $(LIBFT)
	@echo "$(BLUE)make $(GNL) $(END_COLOR)"
	make -C $(GNL)
	@echo "$(BLUE)make $(PARSER)$(END_COLOR)"
	make -C $(PARSER)
	@echo "$(BLUE)make $(EXEC)$(END_COLOR)"
	make -C $(EXEC)
	@echo "$(BLUE)make $(NAME)$(END_COLOR)"
	$(CC) $(CFLAGS) main.c -I . $(MLX_A) $(LIBFT_A) $(GNL_A) -framework OpenGL -framework AppKit -o $(NAME)
#	$(CC) $(CFLAGS) -L $(PARSER)/parsing.a -L $(EXEC)/pipex.a $(LIB_READLINE_LINUX) main.c -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled :)$(END_COLOR)"
# -C	:	make option that tells make to change directory before execution.
endif

clean:
	$(RM) $(NAME)
	make clean -C $(LIBFT)
	make clean -C $(GNL)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)
	make fclean -C $(LIBFT)
	make fclean -C $(GNL)

re: fclean all
	@echo "$(GREEN) Cleaned all and rebuild $(NAME)!$(END_COLOR)"

.PHONY: all clean fclean re
