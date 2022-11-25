#include "../cub3d.h"

void    ceilling_floor_min(t_cub *cub)
{
	unsigned int i = (cub->width / 2);
	int j = 0;
	while (j < (cub->height / 4))
	{
		i = (cub->width / 2);
		while (++i < (unsigned)cub->width - 1)
			cub->addr[(cub->width) * j + i] = 0xFFFFFF;
		j++;
	}
	while (j < (cub->height / 2))
	{
		i = (cub->width / 2);
		while (++i < (unsigned)cub->width - 1)
			cub->addr[(cub->width) * j + i] = createRGB(cub->par.color[1][0], cub->par.color[1][0], cub->par.color[1][0]);
		j++;
	}
}

void    ceilling_floor_max(t_cub *cub)
{
	unsigned int i = 0;
	int j = 0;
	while (j < (cub->height / 2))
	{
		i = 0;
		while (++i < (unsigned)cub->width - 1)
			cub->addr[(cub->width) * j + i] = createRGB(cub->par.color[1][0], cub->par.color[1][1], cub->par.color[1][2]);
		j++;
	}
	while (j < (cub->height - 1))
	{
		i = 0;
		while (++i < (unsigned)cub->width - 1)
			cub->addr[(cub->width) * j + i] = createRGB(cub->par.color[0][0], cub->par.color[0][1], cub->par.color[0][2]);
		j++;
	}
}

/*
^ equation that need to know for drawing raycasting
	* size_of_cube x sceen_hight / distance_rays(cub->p.rx, cub->p.ry)
	! u need to know that the return it should be less then screen_height
	! if it's more then that should make it equal to screen_height
*/