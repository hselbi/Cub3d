#include "cub3d.h"

void    background(t_cub *cub)
{
    int i;
	int j;

	j = 0;
	while (j < cub->height)
	{
		i = 0;
		while (i < cub->width)
		{
			cub->addr[(cub->width) * j + i] = 0x6e6259;
			i++;
		}
		j++;
	}
}