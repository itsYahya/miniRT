#ifndef PARSER_H
#define PARSER_H

int		validatePath(char *path);
int		parser(char *path);
void	parseAmbLightning(char **tokens);
void	parseCamera(char **tokens);
void	parseLight(char **tokens);
void	parseSphere(char **tokens);
void	parsePlane(char **tokens);
void	parseCylinder(char **tokens);

#endif