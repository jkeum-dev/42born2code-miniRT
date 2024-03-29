/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:21:24 by jkeum             #+#    #+#             */
/*   Updated: 2021/03/12 23:35:12 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define _USE_MATH_DEFINES

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_ray		t_ray;
typedef struct s_hit_record	t_hit_record;

typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_ambient	t_ambient;
typedef struct s_scene		t_scene;

typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_triangle	t_triangle;
typedef struct s_cylinder	t_cylinder;
typedef struct s_square		t_square;
typedef struct s_light		t_light;
typedef struct s_phong		t_phong;

typedef struct s_img		t_img;
typedef struct s_vars		t_vars;
typedef struct s_mode		t_mode;

typedef int					t_bool;
# define FALSE 0
# define TRUE 1

# define X 1
# define Y 2
# define Z 3
# define PLUS 4
# define MINUS 5
# define THETA 0.175

typedef int					t_object_type;
# define SP 1
# define PL 2
# define TR 3
# define CY 4
# define SQ 5
# define CAM 6
# define LIGHT_POINT 7
# define OBJECT 8

# define OFF 0
# define TRANSLATE 1
# define ROTATE 2
# define SCALE 3

# define EPSILON 1e-6
# define LUMEN 3

struct	s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct	s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	t_bool		front_face;
	double		tmin;
	double		tmax;
	double		t;
	t_color3	albedo;
};

struct	s_camera
{
	t_point3	orig;
	t_vec3		normal;
	double		viewport_w;
	double		viewport_h;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	left_bottom;
};

struct	s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct	s_ambient
{
	double		ratio;
	t_color3	ambient_color;
};

struct	s_scene
{
	t_canvas		canvas;
	t_object		*camera;
	t_ambient		ambient;
	t_object		*world;
	t_object		*light;
	t_ray			ray;
	t_hit_record	rec;
	int				max_width;
	int				max_height;
	int				min_width;
	int				min_height;
	int				cnt_r;
	int				cnt_a;
	int				cnt_c;
	int				cnt_l;
};

struct	s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	void			*pre;
	t_color3		albedo;
};

struct	s_sphere
{
	t_point3	center;
	double		diameter;
	double		radius;
	double		a;
	double		half_b;
	double		c;
	t_vec3		oc;
	double		discriminant;
	double		sqrtd;
	double		root;
};

struct	s_plane
{
	t_point3	center;
	t_vec3		normal;
};

struct	s_triangle
{
	t_point3	p0;
	t_point3	p1;
	t_point3	p2;
	t_vec3		normal;
	t_vec3		edge0;
	t_vec3		edge1;
	t_vec3		edge2;
	t_vec3		n;
	t_point3	p;
	double		denominator;
	double		d;
	double		root;
};

struct	s_cylinder
{
	t_point3	center;
	t_vec3		normal;
	double		diameter;
	double		radius;
	double		height;
	t_point3	h;
	t_vec3		h_unit;
	t_vec3		co;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;
	double		h_len;
};

struct	s_square
{
	t_point3	center;
	t_vec3		normal;
	double		length;
	t_vec3		op;
	double		denominator;
	double		root;
	t_vec3		n_x;
	t_vec3		n_y;
	t_vec3		cp;
};

struct	s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct	s_phong
{
	t_color3	ambient;
	t_color3	diffuse;
	t_color3	specular;
	t_vec3		light_dir;
	double		light_len;
	t_ray		light_ray;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		kd;
	double		ks;
	double		ksn;
	double		spec;
	double		brightness;
};

struct	s_vars
{
	void		*mlx;
	void		*win;
	t_scene		*scene;
	t_img		*img;
	t_mode		*mode;
	t_object	*cur;
};

struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct	s_mode
{
	t_object_type	selected;
	int				trans;
	int				axis;
	int				sign;
};

#endif
