#include "cub3d.h"

/************ crose closing function *************/

int ft_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
	return (0);
}

/************	keys check	**********/

void	rotation_matrix(t_cub *cub, double angle)
{
	double tmp;

	tmp = cub->x * cos(angle) - cub->y * sin(angle);
	cub->y = cub->x * sin(angle) + cub->y * cos(angle);
	cub->x = tmp;
}

int ft_keys(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	else if (key == W)
	{
		cub->pos_y -= 10;
	}
	else if (key == S)
	{
		cub->pos_y += 10;
	}
	else if (key == A)
	{
		cub->pos_x -= 10;
	}
	else if (key == D)
	{
		cub->pos_x += 10;
	}
	if (key == LEFT)
		rotation_matrix(cub, PI/36);
	if (key == RIGHT)
		rotation_matrix(cub, -PI/36);
	
	sq_draw(cub);
	return (0);
}
