CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = miniRT.exe
BUILD = build/src

HEADERS = inc/miniRT.h inc/pair.h inc/params.h inc/types.h src/algebra/algebra.h src/canvas/canvas.h src/color/color.h src/gtline/get_next_line.h src/list/list.h src/lst_utils/lst_utils.h src/matrix/matrix.h src/mlx_events/mlx_events.h src/parser/parser_.h src/raytracer/raytracer.h src/threads/h_threads.h src/tuple/tuple.h src/utils/utils.h
INC =  -Imlx $(addprefix -I, ${dir ${HEADERS}})
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

CFILES = main miniRT algebra/algebra canvas/canvas color/color_construct color/ft_add_color color/ft_map_color color/ft_merge_color color/ft_multiply_color color/ft_scale_color color/hadamard_product gtline/get_next_line gtline/get_next_line_utils list/ft_lstadd_back list/ft_lstadd_front list/ft_lstclear list/ft_lstdelone list/ft_lstiter list/ft_lstlast list/ft_lstmap list/ft_lstnew list/ft_lstsize lst_utils/lst_object matrix/get_col matrix/get_row matrix/identity matrix/matrix_equal matrix/matrix_invert matrix/matrix_multiply matrix/matrix_tuple_multiply matrix/transform matrix/transforms matrix/transpose mlx_events/events parser/checker parser/get_vect3 parser/orientation_transform parser/parse_ambient_lightning parser/parse_camera parser/parse_color parser/parse_cone parser/parse_cylinder parser/parse_err parser/parse_light parser/parse_plane parser/parse_ratio parser/parse_sphere parser/parser parser/set_transform parser/split_line raytracer/cone raytracer/constructs raytracer/cylinder raytracer/init_info raytracer/plane_inters raytracer/rays raytracer/renderer raytracer/shading raytracer/sphere_inters raytracer/vcamera threads/threads tuple/angle_between tuple/clone tuple/construct_tuple tuple/cross_product tuple/dot_product tuple/is_equal tuple/magnitude tuple/normalize tuple/print_tuple tuple/tuple_calc tuple/tuple_product utils/arr_free utils/arr_print utils/arr_size utils/atoi utils/chomp utils/free utils/ft_getline utils/is_double utils/minmax utils/split utils/stod utils/strdup utils/swap utils/utils
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
