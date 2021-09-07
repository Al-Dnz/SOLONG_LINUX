SRC =	main.c \
		exit_util.c \
		main_util.c \
		map_error.c \
		map_util.c \
		map_array_generator.c \
		map_parser.c \
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

NAME = solong

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	OS_NAME = MAC_OS
	LIBMLX	=	mlx_mac
else
	LIBMLX	=	mlx_linux
	OS_NAME = LINUX
endif

MLX = libmlx.dylib
CC = gcc
LIB = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

#.c.o:
#	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

all:
	@mkdir -p $(OBJ_DIR)
	@(make -C ./libft/)
	@(make -C $(LIBMLX))
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
ifeq ($(UNAME), Darwin)
	${CC} $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) -I $(INC_DIR) -L $(LIBMLX) -l mlx
	@install_name_tool -change $(MLX) @loader_path/$(LIBMLX)/$(MLX) $(NAME)
else
	$(CC) $(CFLAGS) -L$(LIBFT) $(OBJ) -I$(INC) -L $(LIBMLX) -lmlx -lft -lX11 -lbsd -lm -lXext -o $(NAME)
endif
	@echo "\n------------------------------"
	@echo "| => $(NAME) well created ! <= |"
	@echo "------------------------------\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c #$(LIBMLX)/$(MLX) | .gitignore
	${CC} $(CFLAGS) -I $(INC_DIR) -I $(LIBMLX) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@(make clean -C ./libft/)
	@(make clean -C $(LIBMLX))
	@echo "obj deleted"

fclean:	clean
	@rm -rf $(NAME)
	@(make fclean -C ./libft/)
	@echo "\n=> [$(NAME)]: deleted <=\n"

re: fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)