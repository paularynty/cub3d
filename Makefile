RESET 			= \033[0;39m
BLACK			= \033[1;30m
DARK_RED		= \033[1;31m
DARK_GREEN		= \033[1;32m
DARK_YELLOW		= \033[1;33m
DARK_BLUE		= \033[1;34m
DARK_MAGENTA	= \033[1;35m
DARK_CYAN		= \033[1;36m
DARK_GRAY		= \033[0;90m
LIGHT_GRAY		= \033[1;37m
RED				= \033[1;91m
ORANGE 			= \e[1m\e[38;5;202m
YELLOW 			= \033[0;93m
YELLOW_BOLD		= \033[1;93m
GREEN			= \033[1;92m
BLUE 			= \033[0;94m
BLUE_BOLD 		= \033[1;94m
CYAN 			= \033[0;96m
CYAN_BOLD 		= \033[1;96m
MAGENTA 		= \033[1;95m
PINK			= \e[1m\e[38;5;212m
WHITE 			= \033[1;97m

OBJ_READY		= echo "📥 $(ORANGE)Compiled cub3D files!$(RESET)"
COMP_LIBFT		= echo "📝 $(YELLOW)Compiling Libft...$(RESET)"
LIBFT_READY		= echo "📝 $(YELLOW_BOLD)Libft compiled!$(RESET)"
CLEANING		= echo "💧 $(CYAN)Cleaning...$(RESET)"
CLEANED			= echo "💧 $(CYAN_BOLD)Successfully cleaned all object files!$(RESET)"
FCLEANING		= echo "🧼 $(BLUE)Deep cleaning...$(RESET)"
FCLEANED		= echo "🧼 $(BLUE_BOLD)Successfully cleaned all executable files!$(RESET)"
REMAKE			= echo "✅ $(GREEN)Successfully cleaned and rebuilt everything!$(RESET)"
CUB3D_READY		= echo "🕹️  $(GREEN)cub3D ready! Run the program with ./cub3D [path_to_map]$(RESET)"

NAME			= cub3D

SRCDIR			= srcs
OBJDIR			= objs

CUB3D_HEADER	= ./include
LIBFT_DIR		= ./include/libft
LIBFT			= ./$(LIBFT_DIR)/libft.a
MLX_DIR			= ./include/MLX42
MLX				= $(MLX_DIR)/build/libmlx42.a
MLX_HEADER 		= $(MLX_DIR)/include/MLX42
HEADERS 		= -I $(MLX_HEADER) -I $(LIBFT_DIR) -I $(CUB3D_HEADER)

CFLAGS			= -Wall -Wextra -Werror $(HEADERS)
OSFLAGS			= -ldl -lglfw -pthread -lm

SRCS			= $(SRCDIR)/main.c \
				$(SRCDIR)/init/init_game_data.c \
				$(SRCDIR)/init/init.c \
				$(SRCDIR)/minimap/init_minimap.c \
				$(SRCDIR)/minimap/minimap.c \
				$(SRCDIR)/render/render.c \
				$(SRCDIR)/parsing/create_map.c \
				$(SRCDIR)/parsing/map_validation.c \
				$(SRCDIR)/parsing/parsing_utils.c \
				$(SRCDIR)/parsing/read_map.c \
				$(SRCDIR)/utils/utils.c \

OBJS			= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

.DEFAULT_GOAL = all

all: $(NAME) $(LIBFT) $(MLX)

$(LIBFT):
	@if [ ! -f $(LIBFT) ]; then \
		$(COMP_LIBFT); \
		make -s -C $(LIBFT_DIR) > /dev/null; \
		$(LIBFT_READY); \
	fi

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX_DIR); \
	fi
	@if [ ! -d "$(MLX_DIR)/build" ]; then \
		cmake $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null; \
	fi
	@make -s -C $(MLX_DIR)/build -j4 > /dev/null


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@cc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(CUB3D_HEADER)
	@cp $(LIBFT) .
	@cc $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(OSFLAGS) -o $(NAME)
	@$(OBJ_READY)
	@chmod 777 $(NAME)
	@$(CUB3D_READY)

clean:
	@$(CLEANING)
	@rm -rf $(OBJDIR)
	@rm -rf $(MLX_DIR)/build
	@make clean -s -C $(LIBFT_DIR)
	@$(CLEANED)

fclean: clean
	@$(FCLEANING)
	@rm -rf $(NAME)
	@make fclean -s -C $(LIBFT_DIR)
	@rm -rf $(LIBFT)
	@$(FCLEANED)

re:	fclean all
	@$(REMAKE)

.PHONY: all clean fclean re libmlx libft
