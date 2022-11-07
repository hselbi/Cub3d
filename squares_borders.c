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
	while (i < imax)
	{
		j = 64 * y;
		while (j < jmax)
		{	
			cub->addr[(COL * 64) * j + i] = color;
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
	while (j < ROW)
	{
		i = 0;
		while (i < COL)
		{
			if (cub->map[j][i] == 1)
				draw_sq(cub, i, j, 0xF8C95F);
			else
				draw_sq(cub, i, j, 0xEC7063);
			i++;
		}
		j++;
	}
}


/************	drawing orader		**********/

void	draw_line_h(t_cub *cub, int i, int j)
{
	j = j * 64;
	while (i < COL * 64)
	{
		cub->addr[(COL * 64) * j + i] = 0x000000;
		i++;
	}
}

void	draw_line_v(t_cub *cub, int i, int j)
{
	i = 64 * i;
	while (j < ROW * 64)
	{
		cub->addr[(COL * 64) * j + i] = 0x000000;
		j++;
	}
}

void    draw_borders(t_cub *cub)
{
    int i;
    int j;

	i = 0;
	j = 0;
    while (j <= ROW)
    {
		draw_line_h(cub, i, j);
        j++;
    }
	j = 0;
	while (i <= COL)
    {
		draw_line_v(cub, i, j);
        i++;
    }
}
