/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msiesse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:40:03 by msiesse           #+#    #+#             */
/*   Updated: 2020/02/12 13:20:24 by msiesse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

/*
** LIBRARIES --------------------------------------------------------------
*/

# include <SDL.h>
# include <stdint.h>
# include <stdio.h> // a delete
# include <float.h>
# include "libft.h"
# include "color.h"

/*
** MACROS ------------------------------------------------------------------
*/

# define W_WIN 1280
# define H_WIN 720

# define B 0
# define G 1
# define R 2
# define A 3

# define X 0
# define Y 1
# define Z 2

# define ERR_MEM 1
# define ERR_OPEN_FD 2
# define ERR_NOT_VALID_FILE 3
# define ERR_INIT_SDL 4
# define ERR_CREATE_WINDOW 5
# define ERR_CREATE_RENDERER 6

# define SPHERE 0x1
# define PLAN 0x2
# define CYLINDER 0x4
# define CONE 0x8

# define FOV 60.0
# define VIEW 30

# define DIST_MAX 1e21
# define SCALE 1e8

# define M_KEYS 0x40000000
# define OFFSET 0x47

# define PRESSED 1
# define RELEASED 0

# define ROT 3e-2

# define N 50
# define KD 0.9
# define KS 0.1

/*
** TYPEDEFS/UNIONS/STRUCTS -------------------------------------------------
*/

typedef	union				u_color
{
	unsigned int			color;
	unsigned char			channels[4];
}							t_color;

typedef struct				s_vect
{
	float					x;
	float					y;
	float					z;
}							t_vect;

typedef t_vect				t_point;
typedef float				t_angle;
typedef t_darr				t_dobject;
typedef float				t_mat;
typedef float				t_diag;
typedef float				t_float;

typedef struct				s_ray
{
	t_point					origin;
	t_vect					direction;
}							t_ray;

typedef struct				s_sphere
{
	t_point					origin;
	float					rayon;
	float					rayon_square;
}							t_sphere;

typedef struct				s_plan
{
	t_point					plan_point;
	t_vect					normal;
}							t_plan;

typedef struct				s_cylinder
{
	t_point					origin;
	t_vect					direct;
	float					rayon;
	float					rayon_square;
}							t_cylinder;

typedef struct				s_cone
{
	t_point					origin;
	t_vect					direct;
	t_angle					angle;
	float					cos2_angle;
}							t_cone;

typedef struct				s_light
{
	t_point					pos;
	t_color					color;
}							t_light;

typedef struct				s_cam
{
	t_point					pos;
	t_vect					view;
}							t_cam;

typedef union				u_items
{
	t_sphere				sphere;
	t_plan					plan;
	t_cylinder				cylinder;
	t_cone					cone;
}							t_items;

typedef struct				s_object
{
	t_items					item;
	uint8_t					type;
	t_color					color;
}							t_object;

typedef struct				s_linecyl
{
	t_vect					n_cross_a;
	t_vect					b_cross_a;
	float					norm_ncrossa;
	t_point					base;
	float					b_dot_a;
	float					dot_doublecross;
}							t_linecyl;

typedef struct				s_linecone
{
	float					n_dot_a;
	float					bo_dot_a;
	float					n_dot_bo;
	float					norm2_bo;
}							t_linecone;

typedef struct				s_scene
{
	t_dobject				objects;
	t_light					light;
	t_cam					cam;
	t_mat					rot[3][3];
	t_ray					prim_ray;
	t_ray					shadow_ray;
	t_point					p_hit;
	t_vect					n_hit;
	uint8_t					is_in_shadow;
	float					light_dist;
	t_linecyl				linecyl;
	t_linecone				linecone;
	t_mat					rot_x[3][3];
	t_mat					rot_y[3][3];
	t_mat					rot_z[3][3];

}							t_scene;

typedef struct				s_env
{
	SDL_Window				*win;
	SDL_Renderer			*renderer;
	SDL_Event				event;
	int						fd;
	t_scene					scene;
	uint8_t					modif;
	uint8_t					keys[351];
	t_object				*select;
}							t_env;

/*
** FUNCTIONS ---------------------------------------------------------------
*/

/*
** Env functions
*/

void						init_env(t_env *e);
void						init_sdl(t_env *e);

/*
** rendering on screen
*/

void						fill_pixel(SDL_Renderer *renderer, int x, int y
				, t_color color);
void						render_scene(t_env *e);

/*
** Event functions
*/

int							handler_event(t_env *e);
int							move_cam(t_env *e);
uint8_t						choose_object(t_env *e);
uint8_t						move_select(t_env *e);

/*
** File functions
*/

int							read_file(const char *path, t_env *e);

/*
** Points functions
*/

void						copy_point(t_point *dst, t_point src);
t_point						create_point(float x, float y, float z);

/*
** Vect functions
*/

t_vect						create_vect(float x, float y, float z);
t_vect						add_vect(t_vect a, t_vect b);
float						scalar_product(t_vect a, t_vect b);
t_vect						scalar_vect(t_vect a, float c);
t_vect						cross_product(t_vect a, t_vect b);
float						get_norm_vect(t_vect vect);
float						get_norm_vect_square(t_vect vect);
t_vect						normalize_vect(t_vect vect);
int							get_sign_dot_product(t_vect a, t_vect b);
void						get_mat_base(t_scene *scene);
void						product_mat(t_mat mat_a[3][3], t_mat mat_b[3][3],
								t_mat res[3][3]);
void						product_mat_diag(t_mat a[3][3], t_diag diag[3],
								t_mat res[3][3]);
void						product_mat_vect(t_mat a[3][3], t_vect vect
				, t_vect *res);
void						rot_z(t_angle theta, t_mat rot[3][3]);
void						rot_y(t_angle phi, t_mat rot[3][3]);
void						get_rot_x(t_mat rot_x[3][3], t_angle theta);
void						get_rot_y(t_mat rot_y[3][3], t_angle theta);
void						get_rot_z(t_mat rot_z[3][3], t_angle theta);
void						get_rot(t_mat rot[3][3], t_angle theta
				, uint8_t axe);
void						move_point(t_point *point, t_point base);
void						change_base_point(t_mat rot[3][3], t_point *point);

/*
** Ray functions
*/

void						get_primray(int x, int y, t_scene *scene);
void						get_vect_ray(t_angle phi, t_angle theta
				, t_ray *ray);
t_ray						get_shadow_ray(t_scene *scene, t_point p_hit
				, t_light light);

/*
** Intersections functions
*/

t_object					*intersect_prim(t_scene *scene, t_ray prim_ray
				, t_dobject objects, t_point *p_hit);
float						intersect_object(t_scene *scene, t_ray ray
				, t_object object, t_point *hit);
float						intersect_sphere(t_ray ray, t_sphere sphere
				, t_point *hit);
float						intersect_cylinder(t_linecyl *vars, t_ray ray
				, t_cylinder cylinder, t_point *hit);
float						intersect_cone(t_linecone *linecone, t_ray ray
				, t_cone cone, t_point *hit);
uint8_t						intersect_shadow(t_object *object, t_scene *scene
				, t_ray shadow_ray, t_dobject objects);
float						intersect_plan(t_ray ray, t_plan plan
				, t_point *hit);
t_vect						get_nhit(t_scene *scene, t_point p_hit
				, t_object *object);

/*
** Scenes functions
*/

t_scene						init_scene(void);
void						translate_objects(t_scene *scene
				, t_dobject *objects);
void						rotate_objects(t_scene *scene, t_dobject *objects);
void						rotate_objects_x(t_scene *scene, t_dobject *objects
				, int8_t sign);
void						rotate_objects_y(t_scene *scene, t_dobject *objects
				, int8_t sign);
void						rotate_objects_z(t_scene *scene, t_dobject *objects
				, int8_t sign);
void						scale_objects(t_scene *scene);
t_point						*get_point_object(t_object *object);
t_vect						*get_vect_object(t_object *object);

/*
** Limits functions
*/

void						limit_objects(t_scene *scene);
void						limit_sphere(t_sphere *sphere);
void						limit_plan(t_plan *plan);
void						limit_cylinder(t_cylinder *cylinder);
void						limit_cone(t_cone *cone);
void						limit_vect(t_vect *a);

/*
** Color functions
*/

t_color						get_color_pixel(t_scene *scene, t_object *object
				, t_ray shadow_ray, t_vect n_hit);
t_color						k_color(t_color color, float k);
t_color						add_colors(t_color color_a, t_color color_b);

/*
** utilities functions
*/

void						good_exit(t_env *e);
void						error_exit(int err_num, t_env *e);
void						perror_exit(const char *str, t_env *e);
void						free_env(t_env *e);
void						free_scene(t_scene *scene);
t_scene						create_scene_test(void);
float						get_delta(float a, float b, float c);

#endif
