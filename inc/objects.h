#ifndef	SCENEMATERIAL_H
#define	SCENEMATERIAL_H

typedef struct s_vect3
{
	double x;
	double y;
	double z;
}	t_vect3;

typedef enum e_type
{
	E_AMBLIGHTNING = 'A',
	E_CAMERA = 'C',
	E_LIGHT = 'L',
	E_SPHERE = 'S',
	E_PLANE = 'P',
	E_CYLINFER = 'Y'
}	t_type;

typedef struct s_ambLightning
{
	float	ratio;
	int		color;
} t_ambLightning;

typedef struct s_camera
{
	t_vect3	coordinates;
	t_vect3	orientation_vect;
	double	fov;
}	t_camera;

typedef struct s_light
{
	t_vect3	point;
	float	bRatio;
	int		color;
}	t_light;

typedef struct s_sphere
{
	t_vect3	center;
	float	diameter;
	int		color;
}	t_sphere;

typedef struct s_plane
{
	t_vect3	point;
	t_vect3	vect;
	int		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vect3	point;
	t_vect3	vect;
	float	diameter;
	float	height;
	int		color;
}	t_cylinder;

typedef union u_object
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_uobject;

#endif
