CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = miniRT.exe
INC = -I ./inc
BUILD = build

_HFILES = ${wildcard inc/*.h}
_CFILES = ${wildcard src/*.c} ${wildcard src/**/*.c}
CFILES = ${_CFILES:src/%.c=%}
HFILES = ${_HFILES:inc/%.h=%}

OBJS := $(addprefix $(BUILD)/, $(CFILES:=.o))

HEADERS := $(addprefix inc/, $(HFILES:=.h))
all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	$(CC) $(OBJS) -o $(NAME)

$(BUILD)/%.o : src/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(INC)

clean :
	rm -rf $(BUILD)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean all
