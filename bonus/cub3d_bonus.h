/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:10:11 by hselbi            #+#    #+#             */
/*   Updated: 2022/12/09 20:32:39 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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

# define TRUE 1
# define FALSE 0

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../minilibx/mlx.h"
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include "../parsing/cub3d_pars.h"
# include "../parsing/libft/libft.h"

typedef struct s_field
{
	float	dist_plan;
	int		width_text;
	int		texel;
	int		h;
	int		tx;
	int		ty;
	int		flag_h;
	int		flag_v;
	int		i;
	int		j;
	int		dist;
}	t_field;

typedef struct s_dda
{
	int		dx;
	int		dy;
	int		i;
	int		step;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
}	t_dda;

typedef struct s_hor
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	atan;
	int		mx;
	int		my;
	int		mp;
	int		dof;

}	t_hor;

typedef struct s_ver
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	atan;
	int		mx;
	int		my;
	int		mp;
	int		dof;

}	t_ver;

typedef struct s_player
{
	int				i;
	int				j;
	double			x;
	double			y;
	double			mini_x;
	double			mini_y;

	double			prev_x;
	double			prev_y;

	double			dem_x;
	double			dem_y;
	double			dm_x;
	double			dm_y;

	float			hx;
	float			vx;
	float			hy;
	float			vy;
	float			rx;
	float			ry;
	float			dist;
	int				dist_plan;
	int				f_hor;
	int				f_ver;

	double			p_angle;
	unsigned int	colors;
}	t_player;

typedef struct s_minimap
{
	void	*img;
	int		*add;
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
	void	*mlx;
	int		*add;
	void	*img;
	int		width;
	int		height;
	int		endian;
	int		bpp;
	int		line_length;
}	t_text;

typedef struct s_sprite
{
	int		ind;
	void	*farme_one;
	int		width_one;
	int		height_one;

	void	*farme_two;
	int		width_two;
	int		height_two;

	void	*farme_three;
	int		width_three;
	int		height_three;

	void	*farme_four;
	int		width_four;
	int		height_four;

	void	*farme_five;
	int		width_five;
	int		height_five;
}	t_sprite;

typedef struct s_cub
{
	t_player	p;
	t_txt		par;
	t_minimap	mmap;
	t_text		tx_img;
	t_sprite	sprite;
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	char		*relative_path;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			mp;
	int			len;
	int			row;
	int			col;

	int			mini_w;
	int			mini_h;
	int			win_x;
	int			win_y;
	int			width;
	int			height;
	int			flag_x;
	int			flag_y;
	int			mid_x;
	int			mid_y;

	double		degree;
	double		angl;

	float		t_wall;
	float		b_wall;
	float		c_plan;

	char		side;
	int			*no;
	int			no_width;
	int			*so;
	int			so_width;
	int			*we;
	int			we_width;
	int			*ea;
	int			ea_width;

	bool		gun_shot;
	int			mouse_x;
	int			mouse_y;

}	t_cub;

void			init_wind(t_cub *cub);
void			init_img_win(t_cub *cub);
void			init_player(t_cub *cub);
int				mlx_windows(t_cub *cub);

/*		keys		*/

int				advance_keys(int key, t_cub *cub);
int				ft_keys(int key, t_cub *cub);
int				ft_close(t_cub *cub);

void			rotation_matrix(t_cub *cub, double angle);
void			mini_bisector(t_cub *cub);
void			background(t_cub *cub);

/*		celling		*/

unsigned long	create_rgb(int r, int g, int b);
unsigned long	create_yrgb(int t, int r, int g, int b);

/*		square		*/

void			ceilling_floor(t_cub *cub);
int				mouse_hook(int button, int x, int y, t_cub *cub);
void			player_minimap(t_cub *cub);
void			mini_bg(t_cub *cub);
void			minimap(t_cub *cub);
int				pl_pos(char c);

/* minimap */

void			sprite_frames(t_cub *cub);
void			draw_minimap(t_cub *cub);
void			mini_dda_line(int end_x, int end_y, t_cub *cub);

void			hor_ray(t_cub *cub, float ra);
void			ver_ray(t_cub *cub, float ra);

void			shortest(t_player *pl);

void			init_texture(t_cub *cub);

void			ceilling_floor_max(t_cub *cub);
void			v_field(t_cub *cub, int x, float ra);

int				func(int x, int y, t_cub *cub);

void			ft_perror(char *msg);

#endif
