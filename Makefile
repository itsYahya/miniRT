CC = cc
# CFLAGS = -Wall -Wextra -Werror -g
NAME = miniRT.exe
BUILD = build

# libs
MLX_DIR = mlx
MLX_FLAGS = -L./$(MLX_DIR) -l$(MLX_DIR) -framework OpenGL -framework AppKit
MLX_HEADER = ${wildcard mlx/*.h}

HEADERS = ${wildcard inc/*.h} ${wildcard src/*.h} ${wildcard src/**/*.h}
INC =  -Imlx $(addprefix -I, ${dir ${HEADERS}})
_CFILES = ${wildcard src/*.c} ${wildcard src/**/*.c}
CFILES = ${_CFILES:src/%.c=%}

OBJS := $(addprefix $(BUILD)/, $(CFILES:=.o))

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(BUILD)/%.o : src/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean :
	@make clean -C $(MLX_DIR)
	rm -rf $(BUILD)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all
