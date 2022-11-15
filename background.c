#include "cub3d.h"

void    background(t_cub *cub)
{
    int i;
	int j;

	j = 0;
	while (j < cub->height)
	{
		i = 0;
		// printf("* %d\n", j);
		while (i < cub->width)
		{
			// printf("==> %d\n", i);
			cub->addr[(cub->width) * j + i] = 0xFFFFFF;
			i++;
		}
		j++;
	}
}