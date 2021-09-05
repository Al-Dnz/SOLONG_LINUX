SRCS =	main.c \
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
		 
NAME 	=	solong
CC		=	clang
FLAGS	=	-O3 -Wall -Wextra -Werror
INC		=	inc
OBJ		=	obj
SRC		=	src
LIBFT	=	libft
LIBMLX	=	libmlx
INCS	=	$(addprefix $(INC)/, solong.h)
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))

all: init $(NAME)

init:
		mkdir -p $(OBJ)
		make -C $(LIBFT)
		make -C $(LIBMLX)

$(NAME): $(OBJS) $(INCS)
		$(CC) $(FLAGS) -I$(INC) -o $(NAME) $(OBJS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext
		@echo "\n------------------------------"
		@echo "| => $(NAME) well created ! <= |"
		@echo "------------------------------\n"

$(OBJ)/%.o: $(SRC)/%.c $(INCS)
		$(CC) $(FLAGS) -I$(INC) -c $< -o $@

clean:
		rm -rf $(OBJ)
		make -C $(LIBFT) clean
		make -C $(LIBMLX) clean
		@echo "obj deleted"

fclean: clean
		rm -rf $(NAME)
		make -C $(LIBFT) fclean
		@echo "\n=> [$(NAME)]: deleted <=\n"

re: fclean all
