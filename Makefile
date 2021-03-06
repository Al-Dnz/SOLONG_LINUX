SRCS =	main.c \
		exit_util.c \
		main_util.c \
		map_error.c \
		map_util.c \
		map_array_generator.c \
		map_parser.c \
		map_parser_2.c \
		graphic_engine.c \
		draw_util.c \
		key_handler.c \
		move_util.c \
		render_util.c \
		initialisation.c \
		time_handler.c \
		render_sprites.c \
		foe_patrol_handler.c \
		score_displayer.c \
		img_initialisation.c \
		check_case.c \
		ending_screen.c \
		draw_map.c \

NAME = so_long

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
OS_NAME = MAC_OS
LIBMLX	= mlx_mac
else
LIBMLX	= mlx_linux
OS_NAME = LINUX
endif

MLX = libmlx.dylib
CC = clang
LIB = libft/libft.a
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.d))

all:
	@mkdir -p $(OBJ_DIR)
	@(make -C $(LIBFT))
	@(make -C $(LIBMLX))
	@(make -j $(NAME))

$(NAME): $(OBJ)
ifeq ($(UNAME), Darwin)
	${CC} $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) -I$(INC_DIR) -L$(LIBMLX) -I$(LIBMLX) -l mlx 
	@install_name_tool -change $(MLX) @loader_path/$(LIBMLX)/$(MLX) $(NAME)
else
	$(CC) -no-pie $(CFLAGS) $(OBJ) $(LIB) -I$(INC_DIR) -L$(LIBMLX) -I$(LIBMLX) -lmlx -lX11 -lbsd -lm -lXext -o $(NAME)
endif
	@echo "\n------------------------------"
	@echo "| => $(NAME) well created ! <= |"
	@echo "------------------------------\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)
	${CC} $(CFLAGS) -D$(OS_NAME) -I$(INC_DIR) -I$(LIBMLX) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "obj deleted"
	@(make clean -C $(LIBFT))
	@(make clean -C $(LIBMLX))
	
fclean:	clean
	@rm -rf $(NAME)
	@(make fclean -C $(LIBFT))
	@echo "\n=> [$(NAME)]: deleted <=\n"

re: fclean all

.PHONY: all, clean, fclean, re
