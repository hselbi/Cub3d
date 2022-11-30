#include "cub3d.h"


void    mini_draw_sq(t_cub *cub, int x, int y, int color)
{
	int i;
	int j;
	int imax;
	int jmax;

	j = 16 * y;
	i = 16 * x;
	jmax = j + 16;
	imax = i + 16;
	while (i < imax - 1)
	{
		j = 16 * y;
		while (j < jmax - 1)
		{
			cub->addr[(cub->width) * j + i] = color;
			j++;
		}
		i++;
	}
}

void	mini_background(t_cub *cub)
{
	int i = 0;
	int j = 0;
	while (i < cub->max_row * 16)
	{	
		j = 0;
		while (j < cub->col * 16)
		{
			cub->addr[(cub->width) * j + i] = 0x6E6259;
			j++;
		}
		
		i++;
	}
	
}

void	mini_draw_sqs(t_cub *cub)
{
	int i;
	int j;

	j = 0;
	mini_background(cub);
	while ((j < cub->col) && cub->par.map[j])
	{
		i = 0;
		while (i < cub->max_row && cub->par.map[j][i])
		{
			if (cub->par.map[j][i] == '1')
				mini_draw_sq(cub, i, j, 0xF8C95F);
			else
				mini_draw_sq(cub, i, j, 0xEC7063);
			i++;
		}
		j++;
	}
}

void	player_minimap(t_cub *cub)
{
	// printf("%d\n");
	int x = -1;
	int y = 0;
	while (++x < 2)
	{
		y = -1;
		while (++y < 2)
		{
			cub->addr[(cub->width) * ((int)(cub->p.mini_y) + y) + ((int)(cub->p.mini_x) + x)] = 0x00FF00;
		}
		
	}
	
}

void    mini_dplayer(t_cub *cub)
{
    int x = -1;
    int y = 0;
	float	tmp;
	tmp = cub->p.x - (64/2);
	cub->mini.x = tmp / 4;
	tmp = cub->p.y - (64/2);
	cub->mini.y = tmp / 4;
	int	i = cub->mini.x / 16;
	int	j = cub->mini.y / 16;

	while (++x < 2)
	{
		y = -1;
		while (++y < 2)
		{
			if (cub->par.map[j][i] != '0')
			{
				cub->p.x = cub->p.prev_x;
				cub->p.y = cub->p.prev_y;
			}
			cub->addr[(cub->width) * ((int)cub->mini.y + y) + ((int)cub->mini.x + x)] = 0x00FF00;
		}
	}
}

void	mini_bisector(t_cub *cub)
{
	dda_line((int)cub->p.mini_x, (int)(cub->p.mini_x + cub->p.dem_x * 2.5),\
		(int)cub->p.mini_y, (int)(cub->p.mini_y + cub->p.dem_y * 2.5), cub);
}

// void	draw_minimap(t_cub *cub)
// {
	
// }