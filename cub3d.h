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

# define FOV PI/2.0

# define ROW 11
# define COL 15


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include "parsing/cub3d_pars.h"
#include "parsing/libft/libft.h"

typedef struct s_player
{
	double	x;
	double	y;
	double	dem_x;
	double	dem_y;
	float	hx;
	float	vx;
	float	hy;
	float	vy;
	float	rx;
	float	ry;
	double	p_angle;
}	t_player;

typedef struct s_cub
{
	t_player	p;
	t_txt		par;
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

}			t_cub;

int mlx_windows(t_cub *cub);
void my_mlx_pixel(t_cub *data, int x, int y, int color);
void	pix_mlx(t_cub *cub, int x, int y, int color);

/*		keys		*/

int advance_keys(int key, t_cub *cub);

int		ft_keys(int key, t_cub *cub);
void	rotation_matrix(t_cub *cub, double angle);
int		ft_close(t_cub *cub);
void    background(t_cub *cub);

/*		square		*/

void    draw_sq(t_cub *cub, int x, int y, int color);
void	draw_sqs(t_cub *cub);

/* first version ==> sucks	*/
void dda_line(int start_x, int end_x, int start_y, int end_y, t_cub *cub);
/* second version ==> ok */
void dda_line2(int start_x, int end_x, int start_y, int end_y, t_cub *cub);

void my_mlx_pixel(t_cub *data, int x, int y, int color);

void    hor_ray(t_cub *cub, float ra);
void    ver_ray(t_cub *cub, float ra);

/*******************************/
int check_cor(int mx, int my);


void draw_ver(t_cub *cub, int x, int y);
void draw_hori(t_cub *cub, int x, int y);
void drawing_palyer(t_cub *cub);
void angle_fov(t_cub *cub);
void fov_angle(t_cub *cub);
void maps_barriers(t_cub *cub);
void	draw_dir_ray(t_cub *cub, double angle);
void	draw_ray(t_cub *cub);
void new_point(t_cub *cub);
void drawing(t_cub *cub);
int sq_draw(t_cub *cub);

#endif
