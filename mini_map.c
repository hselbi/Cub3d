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
        // printf("%d/%d\n", i, imax);
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

void	mini_draw_sqs(t_cub *cub)
{
	int i;
	int j;

	j = 0;
	while ((j < cub->col) && cub->par.map[j])
	{
		i = 0;
		while (i < cub->max_row && cub->par.map[j][i])
		{
            // print≥f("test\n");
			if (cub->par.map[j][i] == '1')
				mini_draw_sq(cub, i, j, 0xF8C95F);
			else if (cub->par.map[j][i] == '0')
				mini_draw_sq(cub, i, j, 0xEC7063);
			else if (cub->par.map[j][i] != ' ')
				mini_draw_sq(cub, i, j, 0xEA7520);
			i++;
		}
		j++;
	}
}


void    mini_dplayer(t_cub *cub)
{
	// t_minimap mini;
    int x = -1;
    int y = 0;
	float	tmp;
	// 4 + (64 / 2)
	// 1 + x
	// 
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
			if (cub->par.map[j][i] != '0' && !player_pos(cub->par.map[j][i]))
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
	bi_hor_ray(cub, 0);
	bi_ver_ray(cub, 0);
	bi_shortest(cub);
	dda_line2((int)cub->mini.x, (int)cub->mini.rx, (int)cub->mini.y, (int)cub->mini.ry, cub);
}

// void	mini_init_player(t_cub *cub)
// {
// 	int i = 0;
// 	int j = 0;
// 	int stop = 0;
// 	while ((j < cub->col) && cub->par.map[j] && !stop)
// 	{
// 		i = 0;
// 		while (i < cub->max_row && cub->par.map[j][i] && !stop)
// 		{
// 			if (check_player(cub->par.map[j][i]))
// 			{
// 				cub->p.mini_x = i * 16 + (16 / 2);
// 				cub->p.mini_y = j * 16 + (16 / 2);
// 				stop = 1;
// 				break;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	cub->p.p_angle = 0.0;
// 	if (stop && cub->par.map[j - 1][i] == 'N')
// 		cub->p.p_angle = (3 * PI) / 2;
// 	else if (stop && cub->par.map[j - 1][i] == 'S')
// 		cub->p.p_angle = PI / 2;
// 	else if (stop && cub->par.map[j - 1][i] == 'W')
// 		cub->p.p_angle = PI;
// 	else if (stop && cub->par.map[j - 1][i] == 'E')
// 		cub->p.p_angle = 0.0;
// 	cub->p.dem_x = cos(cub->p.p_angle) * 5;
// 	cub->p.dem_y = sin(cub->p.p_angle) * 5;
// 	cub->p.dist_plan = 277;
// }