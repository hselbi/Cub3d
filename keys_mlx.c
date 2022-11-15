#include "cub3d.h"

/************ crose closing function *************/

int ft_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
	return (0);
}

/************	keys check	**********/

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
	if (key == A)
	{
		if (cub->p.p_angle == 0.0)
			cub->p.x -= 5;
		else
		{
			cub->p.x += cub->p.dem_x;
			cub->p.y -= cub->p.dem_y;
		}
	}
	else if (key == D)
	{
		if (cub->p.p_angle == 0.0)
			cub->p.x += 5;
		else
		{
			cub->p.x -= cub->p.dem_x;
			cub->p.y += cub->p.dem_y;
		}
	}
	if (key == LEFT)
	{
		cub->p.p_angle -= 0.1;
		if (cub->p.p_angle < 0)
			cub->p.p_angle += 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	if (key == RIGHT)
	{
		cub->p.p_angle += 0.1;
		if (cub->p.p_angle > 2 * PI)
			cub->p.p_angle -= 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	return (0);
}
