CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = miniRT.exe
BUILD = build/src

HEADERS = ${wildcard inc/*.h} ${wildcard src/*.h} ${wildcard src/**/*.h}
INC =  -Imlx $(addprefix -I, ${dir ${HEADERS}})
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

_CFILES = ${wildcard src/*.c} ${wildcard src/**/*.c}
CFILES = ${_CFILES:src/%.c=%}
OBJS = $(addprefix $(BUILD)/, $(CFILES:=.o))

all : $(NAME)

$(BUILD)/%.o : src/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)


$(NAME) : $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all
