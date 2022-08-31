#include "sceneMaterial.h"
#include <stdio.h>
#include "parser.h"

void	parseSphere(char **tokens, t__data *data)
{
	data->camera.fov = 20;
	printf("here we go again sphere %s\n", tokens[0]);
}

void	parsePlane(char **tokens, t__data *data)
{
	data->camera.fov = 99;
	printf("here we go plane %s\n", tokens[0]);
}

void	parseCylinder(char **tokens, t__data *data)
{
	data->camera.fov = 8;
	printf("here we go again cylinder %s\n", tokens[0]);
}