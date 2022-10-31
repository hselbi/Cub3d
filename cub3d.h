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


# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

typedef struct s_cub
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		win_x;
	int		win_y;
	int		flag_x;
	int		flag_y;
	int		mid_x;
	int		mid_y;

	int		pos_x;
	int		pos_y;


}			t_cub;


#endif

/*
3.3	1280 × 720 (HD)
*/