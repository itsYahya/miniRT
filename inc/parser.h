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
t_vect3	get_vect3(const char *arg);
t_vect3	get_orientation_vect3(const char *arg);
float	get_ratio(const char *token);
void	multiple_elm_exit(char *id);
void	invalid_argements(char *id);
void	invalid_identifier(void);
int		get_color(char *token);

#endif
