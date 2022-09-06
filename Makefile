CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = miniRT.exe
INC = -I./inc -Imlx
BUILD = build

# libs
MLX_DIR = mlx
MLX_FLAGS = -L./$(MLX_DIR) -l$(MLX_DIR) -framework OpenGL -framework AppKit
MLX_HEADER = ${wildcard mlx/*.h}

_HFILES = ${wildcard inc/*.h}
_CFILES = ${wildcard src/*.c} ${wildcard src/**/*.c}
CFILES = ${_CFILES:src/%.c=%}
HFILES = ${_HFILES:inc/%.h=%}

OBJS := $(addprefix $(BUILD)/, $(CFILES:=.o))

HEADERS := $(addprefix inc/, $(HFILES:=.h)) $(MLX_HEADER)
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
