#include "objects.h"
#include <stdio.h>
#include "parser.h"


void	parseCylinder(char **tokens, t__data *data)
{
	data->camera.fov = 8;
	printf("here we go again cylinder %s\n", tokens[0]);
}
