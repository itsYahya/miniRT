# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 17:57:12 by yel-mrab          #+#    #+#              #
#    Updated: 2022/08/24 21:30:03 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = miniRT.exe
INC = -I ./inc
BUILD = build

CFILES = main utils/utils gtline/get_next_line  gtline/get_next_line_utils
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