#ifndef CUB3D_H
# define CUB3D_H


//==> exit
# define ESC 53

// ==> to up
# define UP 126
# define W 13

// ==> to down
# define DOWN 125
# define S 1

// ==> to left
# define LEFT 124
# define D 2

// ==> to right
# define RIGHT 123
# define A 0


// define π value
# define PI 3.141592653589793238
# define P1 PI/2
# define P2 3*PI/2
# define FOV PI/2.0

# define ROW 11
# define COL 15

#include<stdbool.h>  
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./minilibx_opengl_20191021/mlx.h"
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include "parsing/cub3d_pars.h"
#include "parsing/libft/libft.h"

typedef struct s_player
{
	double	x;
	double	y;
	double	mini_x;
	double	mini_y;

	double	prev_x;
	double	prev_y;
	
	double	dem_x;
	double	dem_y;
	double	dm_x;
	double	dm_y;

	float	hx;
	float	vx;
	float	hy;
	float	vy;
	float	rx;
	float	ry;
	float	dist;
	int		dist_plan;
	int		f_hor;
	int		f_ver;
	
	double	p_angle;
	unsigned int		colors;
}	t_player;

typedef struct s_minimap
{
	float	mini_x;
	float	mini_y;
	float	x;
	float	y;
	int		width;
	int		height;
	float	rays;
	float	rx;
	float	ry;
	
}	t_minimap;


typedef struct s_text
{
	void *mlx;
	int *add;
	void *img;
	int	width;
	int height;
	int endian;
	int bpp;
	int line_length;
} t_text;


typedef struct s_cub
{
	t_player	p;
	t_txt		par;
	t_minimap	mini;
	t_text		tx_img;
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	char	*relative_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map[ROW][COL];
	int		mp;
	int		len;
	int		max_row;
	int		col;

	int		win_x;
	int		win_y;
	int		width;
	int		height;
	int		flag_x;
	int		flag_y;
	int		mid_x;
	int		mid_y;

	int		x;
	int		y;
	int		pos_x;
	int		pos_y;
	double	degree;
	double	angl;

	float	t_wall;
	float	b_wall;
	float	c_plan;


	FILE	*file_out;
	char	side;
	// int	*texture[5];
	int	*no;
	int	no_width;
	int	*so;
	int	so_width;
	int	*we;
	int	we_width;
	int	*ea;
	int	ea_width;
	// mouse
	int	mouse_x;
	int	mouse_y;

}			t_cub;

int mlx_windows(t_cub *cub);
void my_mlx_pixel(t_cub *data, int x, int y, int color);
void	pix_mlx(t_cub *cub, int x, int y, int color);

/*		keys		*/

void	mini_bisector(t_cub *cub);
int advance_keys(int key, t_cub *cub);

int		ft_keys(int key, t_cub *cub);
void	rotation_matrix(t_cub *cub, double angle);
int		ft_close(t_cub *cub);
void    background(t_cub *cub);
void	bi_shortest(t_cub *cub);

/*		celling		*/

unsigned long createRGB(int r, int g, int b);

/*		square		*/

void    draw_sq(t_cub *cub, int x, int y, int color);
void	draw_sqs(t_cub *cub);
void    mini_draw_sq(t_cub *cub, int x, int y, int color);
void	mini_draw_sqs(t_cub *cub);
void    ceilling_floor(t_cub *cub);

// void    mini_dplayer(t_cub *cub);
void	player_minimap(t_cub *cub);

int	player_pos(char c);
int	pl_pos(char c);

/* second version ==> ok */

void dda_line(int start_x, int end_x, int start_y, int end_y, t_cub *cub);

void my_mlx_pixel(t_cub *data, int x, int y, int color);

void    hor_ray(t_cub *cub, float ra);
void    ver_ray(t_cub *cub, float ra);
void    bi_ver_ray(t_cub *cub, float ra);
void    bi_hor_ray(t_cub *cub, float ra);

/*******************************/

int check_cor(int mx, int my);

void	shortest(t_player *pl);

void    init_texture(t_cub *cub);

void drawing_palyer(t_cub *cub);
void angle_fov(t_cub *cub);
void fov_angle(t_cub *cub);
void maps_barriers(t_cub *cub);
void	draw_dir_ray(t_cub *cub, double angle);
void	draw_ray(t_cub *cub);
void new_point(t_cub *cub);
void drawing(t_cub *cub);
int sq_draw(t_cub *cub);


/*
* raycasting
*/

void    ceilling_floor_min(t_cub *cub);
void    ceilling_floor_max(t_cub *cub);
void    v_field(t_cub *cub, int x, float ra);

int		func(int x, int y, t_cub *cub);

#endif
