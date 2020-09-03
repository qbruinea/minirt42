
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tcurinie <tcurinie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:57:53 by Tcurinie          #+#    #+#             */
/*   Updated: 2020/05/27 16:52:52 by Tcurinie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define whitespace " \n\t\r\v\f"
#include "./key.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../Libft/libft.h"
#include "./mlx.h"
#include "./mlx_int.h"

/* structures Generales */

typedef struct	s_rt
{
	void	*mlx;
	void	*win;
}				t_rt;

typedef struct	s_res
{
	int		x;
	int		y;
}				t_res;

typedef struct 	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

/* Divers */

typedef struct	s_amb
{
	double	intensity;
	t_color	rgb;
}				t_amb;

typedef struct 	s_coor
{
	double	x;
	double	y;
	double	z;
}				t_coor;

typedef struct 	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;


/* Basic Elements */

typedef struct	s_cam
{
	t_coor	coord;
	t_vec3	vec_cam;
	double	fov;
}				t_cam;

typedef struct	s_light
{
	t_coor	coord;
	double 	intensity;
	t_color	rgb;
}				t_light;

/* structures Objets */

typedef struct	s_sphere
{
	t_coor	coord;
	double	diam;
	t_color	rgb;
}				t_sphere;

typedef struct	s_plane
{
	t_coor	coord;
	t_vec3	vec;
	t_color	rgb;
}				t_plane;

typedef struct	s_square
{
	t_coor	coord;
	t_vec3	vec;
	double	height;
	t_color	rgb;
}				t_square;

typedef	struct	s_cyl
{
	t_coor	coord;
	t_vec3	vec;
	t_color	rgb;
	double	diam;
	double	height;
}				t_cyl;

typedef	struct	s_tria
{
	t_coor	coord_un;
	t_coor	coord_dos;
	t_coor	coord_tres;
	t_color	rgb;
}				t_tria;

typedef	struct 	s_minirt
{
	t_rt		mlx;
	int			count_res;
	int			count_amb;
	int			count_cam;
	int			count_light;
	int			count_sp;
	int			count_pl;
	int			count_sq;
	int			count_cy;
	int			count_tr;
	int			count_error;
	t_res		tab_res;
	t_amb		tab_amb;
	t_cam		*tab_cam;
	t_light		*tab_light;
	t_sphere	*tab_sp;
	t_plane		*tab_pl;
	t_square	*tab_sq;
	t_cyl		*tab_cyl;
	t_tria		*tab_tr;
}				t_minirt;

typedef struct	s_fonction
{
	int			(*tabfunction[9])(char *w, t_minirt *base);
	void		(*tabfunction_get[9])(char *w, t_minirt *base);
	char		*tabindex[10];
	int			index;
}				t_fonction;

/* Functions free */

int		free_everything(t_minirt *base, t_fonction *check_func, int retend);
void	free_struct_tab(t_minirt *base);

/* Functions Parser */

int		find_index(char **tab, char *element);
int		check_and_freete(t_minirt *base, t_fonction *check_func, char *fd);
void 	get_and_freete(t_minirt *base, t_fonction *tab_func, char *fd);

/* Functions init_struct */

void	init_struct_check(t_fonction *check_func);
void    init_struct_get(t_fonction *get_func);
void	init_struct_cmp(t_minirt *base);

/* Functions init_forms */

void	init_sphere(t_minirt *base);
void	init_plane(t_minirt *base);
void	init_square(t_minirt *base);
void	init_cylinder(t_minirt *base);
void	init_triangle(t_minirt *base);

/* Functions init_view */

void	init_forms_and_views(t_minirt *base);
void	init_res(t_minirt *base);
void	init_amb(t_minirt *base);
void	init_cam(t_minirt *base);
void	init_light(t_minirt *base);

/* Functions check_param */

int		check_lightrange(char **lrange, int i, int p_index);
int		check_fov(char **fov, int p_index);
int		check_xyz(char **coor, int i, int p_index, char is_vec);
int		check_diam_or_high(char **diam, int p_index, char is_h_or_d);
int		check_rgb(char **rgb, int i, int p_index);

/* Functions check_view */

int		check_nb_param(char **param, int i, int nb_param);
int 	check_res(char *line, t_minirt *base);
int 	check_amb(char *line, t_minirt *base);
int		check_cam(char *line, t_minirt *base);
int		check_light(char *line, t_minirt *base);

/* Functions check_forms */

int		check_sphere(char *line, t_minirt *base);
int		check_plane(char *line, t_minirt *base);
int		check_square(char *line, t_minirt *base);
int		check_cyl(char *line, t_minirt *base);
int		check_triangle(char *line, t_minirt *base);

/* Functions get_param */

t_coor	get_xyz(char **coor, int p_index);
t_color	get_rgb(char **rbg, int p_index);
t_vec3	get_vec_xyz(char **vcoor, int p_index);

/* Functions get_view */

void    get_res(char *line, t_minirt *base);
void    get_amb(char *line, t_minirt *base);
void    get_cam(char *line, t_minirt *base);
void    get_light(char *line, t_minirt *base);

/* Functions get_forms */

void	get_sphere(char *line, t_minirt *base);
void	get_plane(char *line, t_minirt *base);
void	get_square(char *line, t_minirt *base);
void	get_cyl(char *line, t_minirt *base);
void	get_triangle(char *line, t_minirt *base);

/* Functions set_param */

t_color	set_rgb(int r, int g, int b);
t_coor	set_xyz(double x, double y, double z);
t_vec3	set_xyzvec(double x, double y, double z);

#endif
