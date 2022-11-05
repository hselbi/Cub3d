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

// ==> add iteration
# define E 14

// ==> substracte iteration
# define R 15

// ==> changing the iteration
# define Z 6

// ==> default of the iteration for julia
# define X 7

// ==> default of the iteration for mandelbrot
# define C 8

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

typedef struct s_cub
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	char	*relative_path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map[ROW][COL];

	int		win_x;
	int		win_y;
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

	int		down_y;
	int		up_y;
	// int		down_x;
	// int		up_x;

}			t_cub;

void mlx_windows(t_cub *cub);
void my_mlx_pixel(t_cub *data, int x, int y, int color);
void	pix_mlx(t_cub *cub, int x, int y, int color);

/*		keys		*/

int		ft_keys(int key, t_cub *cub);
void	rotation_matrix(t_cub *cub, double angle);
int		ft_close(t_cub *cub);

/*		square		*/

void    draw_sq(t_cub *cub, int x, int y, int color);
void	draw_sqs(t_cub *cub);

/*			borders			*/

void	draw_line_h(t_cub *cub, int i, int j);
void	draw_line_v(t_cub *cub, int i, int j);
void    draw_borders(t_cub *cub);


void dda_line(int start_x, int end_x, int start_y, int end_y, t_cub *cub);
void my_mlx_pixel(t_cub *data, int x, int y, int color);

/*******************************/
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

/*
3.3	1280 × 720 (HD)
*/