#include "sceneMaterial.h"
#include <stdio.h>
#include "parser.h"

void	parseLight(char **tokens, t__data *data)
{
	data->camera.fov = 99;
	printf("here we go light %s\n", tokens[0]);
}
