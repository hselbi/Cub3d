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

	// if (cub->degree < 0)
	// 	cub->degree += 2 * PI;
	// else if (cub->degree > 2 * PI)
	// 	cub->degree -= 2 * PI;
	tmp = cub->x * cos(angle) - cub->y * sin(angle);
	cub->y = cub->x * sin(angle) + cub->y * cos(angle);
	cub->x = tmp;
}

int ft_keys(int key, t_cub *cub)
{
	// printf("%d\n", key);
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
	return (0);
}


/*
^ need to fix the problem of the W and S  keys with angles
*/

int advance_keys(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	else if (key == W)
	{
		if (cub->p.p_angle == 0.0)
			cub->p.y -= 5;
		else
		{
			cub->p.x += cub->p.dem_x;
			cub->p.y += cub->p.dem_y;
		}
	}
	else if (key == S)
	{
		if (cub->p.p_angle == 0.0)
			cub->p.y += 5;
		else
		{
			cub->p.x -= cub->p.dem_x;
			cub->p.y -= cub->p.dem_y;
		}
	}
	else if (key == A)
	{
		cub->p.p_angle -= 0.1;
		if (cub->p.p_angle <= 0)
			cub->p.p_angle += 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
		// cub->p.x -= cub->p.dem_x;
		// cub->p.y += cub->p.dem_y;
	}
	else if (key == D)
	{
		cub->p.p_angle += 0.1;
		if (cub->p.p_angle >= 2 * PI)
			cub->p.p_angle -= 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
		// cub->p.x += cub->p.dem_x;
		// cub->p.y -= cub->p.dem_y;
	}
	// if (key == LEFT)
	// {
	// 	cub->p.p_angle -= 0.1;
	// 	if (cub->p.p_angle < 0)
	// 		cub->p.p_angle += 2 * PI;
	// 	cub->p.dem_x = cos(cub->p.p_angle) * 5;
	// 	cub->p.dem_y = sin(cub->p.p_angle) * 5;
	// }
	// if (key == RIGHT)
	// {
	// 	cub->p.p_angle += 0.1;
	// 	if (cub->p.p_angle > 2 * PI)
	// 		cub->p.p_angle -= 2 * PI;
	// 	cub->p.dem_x = cos(cub->p.p_angle) * 5;
	// 	cub->p.dem_y = sin(cub->p.p_angle) * 5;
	// }
	return (0);
}