#include "cub3d.h"

void mini_bg(t_cub *cub)
{
    int start_y = 0;
    int end_y = cub->mini_w;
    int start_x = 0;
    int end_x = cub->mini_h;
	while (start_y < end_y)
	{
		start_x = 0;
		while (start_x < end_x)
		{
			cub->mmap.add[(cub->mini_w) * start_y + start_x] = 0x6E6259;
			start_x++;
		}
		start_y++;
	}
}

void    minimap(t_cub *cub)
{

    mini_bg(cub);
}

void	player_minimap(t_cub *cub)
{
	int x = -3;
	int y = -3;
	while (++x < 2)
	{
		y = -3;
		while (++y < 2)
		{
			cub->mmap.add[cub->mini_w * (cub->mini_h/2 + y) + (cub->mini_w/2 + x)] = 0x00FF00;
		}	
	}
}


void	mini_bisector(t_cub *cub)
{
	mini_dda_line(cub->mini_w/2, (int)(cub->mini_w/2 + cub->p.dem_x * 2.5),\
		cub->mini_h/2, (int)(cub->mini_h/2 + cub->p.dem_y * 2.5), cub);
}

static void    draw_minisq(t_cub *cub, int x, int y, int color)
{
	int i;
	int j;
	int imax;
	int jmax;

	j = 20 * y;
	i = 20 * x;
	jmax = j + 20;
	imax = i + 20;
	while (i < imax - 1)
	{
		j = 20 * y;
		while (j < jmax - 1)
		{
			cub->mmap.add[(cub->mini_w * j) + i] = color;
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_cub *cub)
{
	mini_bg(cub);
	int	p_j = (int)((cub->p.y) / 64);
	int	p_i = (int)((cub->p.x) / 64);

	int i = 0;
	int j = 0;
	int flag_i = 0;
	int flag_j = 0;
	while (j < 9)
	{
		i = 0;
		while (i < 9)
		{
			flag_j = 4 - j;
			flag_i = 4 - i;
			flag_i = p_i - flag_i;
			flag_j = p_j - flag_j;
			if (flag_i < 0 || flag_i >= cub->max_row || flag_j < 0 || flag_j >= cub->col){}
			else if (cub->par.map[flag_j][flag_i] != '1')
				draw_minisq(cub, (i), (j), 0xF8A95F);
			else if (cub->par.map[flag_j][flag_i] == '1')
				draw_minisq(cub, (i), (j), 0xb2a562);
			i++;
		}
		j++;	
	}
	player_minimap(cub);
	mini_bisector(cub);
}