#ifndef PARSER_H
#define PARSER_H

#include "miniRT.h"

int		validatePath(char *path);
int		parser(char *path, t__data *data);
void	parseAmbLightning(char **tokens, t__data *data);
void	parseCamera(char **tokens, t__data *data);
void	parseLight(char **tokens, t__data *data);
void	parseSphere(char **tokens, t__data *data);
void	parsePlane(char **tokens, t__data *data);
void	parseCylinder(char **tokens, t__data *data);

#endif