#include "../cub3d.h"

void    ceilling_floor_min(t_cub *cub)
{
	unsigned int i = (cub->win_x / 2);
	int j = 0;
	while (j < (cub->win_y / 4))
	{
		i = (cub->win_x / 2);
		while (++i < (unsigned)cub->win_x - 1)
			cub->addr[(cub->win_x) * j + i] = 0xFFFFFF;
		j++;
	}
	while (j < (cub->win_y / 2))
	{
		i = (cub->win_x / 2);
		while (++i < (unsigned)cub->win_x - 1)
			cub->addr[(cub->win_x) * j + i] = 0xFF24A4;
		j++;
	}
}

void    ceilling_floor_max(t_cub *cub)
{
	unsigned int i = (cub->win_x / 2);
	int j = 0;
	while (j < (cub->win_y / 4))
	{
		i = (cub->win_x / 2);
		while (++i < (unsigned)cub->win_x - 1)
			cub->addr[(cub->win_x) * j + i] = 0xFFFFFF;
		j++;
	}
	while (j < (cub->win_y / 2))
	{
		i = (cub->win_x / 2);
		while (++i < (unsigned)cub->win_x - 1)
			cub->addr[(cub->win_x) * j + i] = 0xFF24A4;
		j++;
	}
}

/*
^ equation that need to know for drawing raycasting
	* size_of_cube x sceen_hight / distance_rays(cub->p.rx, cub->p.ry)
	! u need to know that the return it should be less then screen_height
	! if it's more then that should make it equal to screen_height
*/