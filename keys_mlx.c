#include "cub3d.h"

/*
*	this is for escape (esc)
*/

int ft_close(t_cub *cub)
{
	if(!mlx_destroy_window(cub->mlx, cub->win))
		exit(0);
	return (0);
}

/*
* this is key function 
*/

int advance_keys(int key, t_cub *cub)
{
	// printf("%d\n", key);
	if (key == ESC)
		ft_close(cub);
	else if (key == W)
	{
		cub->p.prev_x = cub->p.x;
		cub->p.prev_y = cub->p.y;
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
		cub->p.prev_x = cub->p.x;
		cub->p.prev_y = cub->p.y;
		if (cub->p.p_angle == 0.0)
			cub->p.y += 5;
		else
		{
			cub->p.x -= cub->p.dem_x;
			cub->p.y -= cub->p.dem_y;
		}
	}
	if (key == D)
	{
		cub->p.prev_x = cub->p.x;
		cub->p.prev_y = cub->p.y;
		if (cub->p.p_angle == 0.0 || cub->p.p_angle == PI || cub->p.p_angle == PI/2 || cub->p.p_angle == (3 * PI)/2)
			cub->p.x -= 5;
		else
		{
			cub->p.x += cub->p.dem_x;
			cub->p.y -= cub->p.dem_y;
		}
	}
	else if (key == A)
	{
		cub->p.prev_x = cub->p.x;
		cub->p.prev_y = cub->p.y;
		if (cub->p.p_angle == 0.0 || cub->p.p_angle == PI || cub->p.p_angle == PI/2 || cub->p.p_angle == (3 * PI)/2)
			cub->p.x += 5;
		else
		{
			cub->p.x -= cub->p.dem_x;
			cub->p.y += cub->p.dem_y;
		}
	}
	if (key == RIGHT)
	{
		cub->p.p_angle -= 0.1;
		if (cub->p.p_angle < 0)
			cub->p.p_angle += 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	if (key == LEFT)
	{
		cub->p.p_angle += 0.1;
		if (cub->p.p_angle > 2 * PI)
			cub->p.p_angle -= 2 * PI;
		cub->p.dem_x = cos(cub->p.p_angle) * 5;
		cub->p.dem_y = sin(cub->p.p_angle) * 5;
	}
	return (0);
}
