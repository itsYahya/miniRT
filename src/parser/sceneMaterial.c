#include "sceneMaterial.h"
#include <stdio.h>
#include "parser.h"

void	parseAmbLightning(char **tokens, t__data *data)
{
	data->camera.fov = 99;
	printf("here we go ambLightning %s\n", tokens[0]);
}

void	parseCamera(char **tokens, t__data *data)
{
	data->camera.fov = 99;
	printf("here we go camere %s\n", tokens[0]);
}

void	parseLight(char **tokens, t__data *data)
{
	data->camera.fov = 99;
	printf("here we go light %s\n", tokens[0]);
}