#ifndef	SCENEMATERIAL_H
#define	SCENEMATERIAL_H

typedef struct s_point
{
	int	x;
	int	y;
	int z;
}	t_point;

typedef enum e_type
{
	ambLightning = 'A',
	camera = 'C',
	light = 'L',
	sphere = 'S',
	plane = 'P',
	cylinfer = 'Y'
}	t_type;

typedef struct s_ambLightning
{
	float	ratio;
	int		color;
} t_ambLightning;

typedef struct s_camera
{
	t_point	point;
	t_point	vect;
	int		fov;
}	t_camera;

typedef struct s_light
{
	t_point	point;
	float	bRatio;
	int		color;
}	t_light;

typedef struct s_sphere
{
	t_point	center;
	float	diameter;
	int		color;
}	t_sphere;

typedef struct s_plane
{
	t_point	point;
	t_point	vect;
	int		color;
}	t_plane;

typedef struct s_cylinder
{
	t_point	point;
	t_point	vect;
	float	diameter;
	float	height;
	int		color;
}	t_cylinder;

typedef union u_objs
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_objs;

typedef struct s_object
{
	t_type	type;
	t_objs	content;
}	t_object;


#endif