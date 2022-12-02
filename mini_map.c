#include "cub3d.h"


void    mini_draw_sq(t_cub *cub, int x, int y, int color)
{
	int i;
	int j;
	int imax;
	int jmax;

	j = 32 * y;
	i = 32 * x;
	jmax = j + 32;
	imax = i + 32;
	// int start_y = (int)(cub->p.mini_y - 100);
    // int end_y = (int)(cub->p.mini_y + 100) ;
    // int start_x = (int)(cub->p.mini_x - 100);
    // int end_x = (int)(cub->p.mini_x + 100);
	while (i < imax - 1)
	{
		j = 32 * y;
		while (j < jmax - 1)
		{
			cub->addr[(cub->width) * (j + 10) + i + 10] = color;
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

	i = (int)((cub->p.x - 32)/64);
	j = (int)((cub->p.y - 32)/64);
	// printf("pos i = %d/%f\n", i, cub->p.x);
	// printf("pos j = %d/%f\n", j, cub->p.y);
	// mini_background(cub);
	mini_bg(cub);
	int ending_j = (int)((cub->p.y - 32)/64) + 4;
	printf("pos j = %d/%d\n", j, ending_j);
	int ending_i = (int)((cub->p.x - 32)/64) + 4;
	printf("pos i = %d/%d\n", i, ending_i);
	while ((j < ending_j) && cub->par.map[j][i])
	{
		i = (int)((cub->p.x - 32)/64);
		while ((i < ending_i) && cub->par.map[j][i])
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


// void    mini_dplayer(t_cub *cub)
// {
//     int x = -1;
//     int y = 0;
// 	float	tmp;
// 	tmp = cub->p.x - (64/2);
// 	cub->mmap.x = tmp / 4;
// 	tmp = cub->p.y - (64/2);
// 	cub->mmap.y = tmp / 4;
// 	int	i = cub->mmap.x / 16;
// 	int	j = cub->mmap.y / 16;

// 	while (++x < 2)
// 	{
// 		y = -1;
// 		while (++y < 2)
// 		{
// 			if (cub->par.map[j][i] != '0')
// 			{
// 				cub->p.x = cub->p.prev_x;
// 				cub->p.y = cub->p.prev_y;
// 			}
// 			cub->addr[(cub->width) * ((int)cub->mmap.y + y) + ((int)cub->mmap.x + x)] = 0x00FF00;
// 		}
// 	}
// }

// void	mini_bisector(t_cub *cub)
// {
// 	dda_line((int)cub->p.mini_x, (int)(cub->p.mini_x + cub->p.dem_x * 2.5),\
// 		(int)cub->p.mini_y, (int)(cub->p.mini_y + cub->p.dem_y * 2.5), cub);
// }

// void	draw_minimap(t_cub *cub)
// {
	
// }