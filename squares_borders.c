#include "cub3d.h"

/************	drawing square		**********/

void    draw_sq(t_cub *cub, int x, int y, int color)
{
	int i;
	int j;
	int imax;
	int jmax;

	j = 64 * y;
	i = 64 * x;
	jmax = j + 64;
	imax = i + 64;
	while (i < imax - 1)
	{
		j = 64 * y;
		while (j < jmax - 1)
		{
			cub->addr[(cub->width) * j + i] = color;
			j++;
		}
		i++;
	}
}

/************	drawing squares		**********/

void	draw_sqs(t_cub *cub)
{
	int i;
	int j;

	j = 0;
	while ((j < cub->col) && cub->par.map[j])
	{
		i = 0;
		while (i < cub->max_row && cub->par.map[j][i])
		{
			// printf("map[%d][%d] ==> %c\n", j, i, cub->par.map[j][i]);
			if (cub->par.map[j][i] == '1')
				draw_sq(cub, i, j, 0xF8C95F);
			else if (cub->par.map[j][i] == '0')
				draw_sq(cub, i, j, 0xEC7063);
			else if (cub->par.map[j][i] != ' ')
				draw_sq(cub, i, j, 0xEA7520);
			i++;
		}
		j++;
	}
}
