CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = miniRT.exe
INC = -I ./inc
BUILD = build

CFILES = main \
		utils/utils utils/split \
		gtline/get_next_line  gtline/get_next_line_utils \
		parser/checker parser/parser parser/sceneMaterial parser/sceneObjects\
		list/ft_lstadd_back list/ft_lstadd_front list/ft_lstclear \
		list/ft_lstdelone list/ft_lstiter list/ft_lstlast list/ft_lstmap \
		list/ft_lstnew list/ft_lstsize


OBJS := $(addprefix $(BUILD)/, $(CFILES:=.o))

HFILES = miniRT
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
