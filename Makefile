CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = miniRT.exe
TESTNAME = test_miniRT
BUILD = build/src
TESTBUILD = build/tests

# libs
MLX_DIR = mlx
MLX_FLAGS = -L./$(MLX_DIR) -l$(MLX_DIR) -framework OpenGL -framework AppKit
MLX_HEADER = ${wildcard mlx/*.h}

HEADERS = ${wildcard inc/*.h} ${wildcard src/*.h} ${wildcard src/**/*.h}
INC =  -Imlx $(addprefix -I, ${dir ${HEADERS}})

_CFILES = ${wildcard src/*.c} ${wildcard src/**/*.c}
_CFILES := ${filter-out ${wildcard src/tests/*.c}, ${_CFILES}}
CFILES = ${_CFILES:src/%.c=%}
OBJS = $(addprefix $(BUILD)/, $(CFILES:=.o))

all : $(NAME)

$(TESTBUILD)/%.o : src/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(BUILD)/%.o : src/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)


$(NAME) : $(OBJS) $(HEADERS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

clean:
	@make clean -C $(MLX_DIR)
	rm -rf $(BUILD) $(TESTBUILD)

fclean: clean
	rm -rf $(NAME) $(TESTNAME)

re: fclean all

_CTEST_FILES := ${wildcard src/*.c} ${wildcard src/**/*.c}
_CTEST_FILES := ${filter-out src/main.c, $(_CTEST_FILES)}
CTEST_FILES := ${_CTEST_FILES:src/%.c=%}
TEST_OBJS = $(addprefix $(TESTBUILD)/, $(CTEST_FILES:=.o))

test: $(TEST_OBJS) $(HEADERS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(TEST_OBJS) -o $(TESTNAME)

.PHONY : re fclean clean all test
