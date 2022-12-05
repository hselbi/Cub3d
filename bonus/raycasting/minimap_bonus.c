#include "../cub3d.h"

void	player_minimap(t_cub *cub)
{
	int	x;
	int	y;

	x = -3;
	y = -3;
	while (++x < 2)
	{
		y = -3;
		while (++y < 2)
			cub->mmap.add[cub->mini_w * \
				(cub->mini_h / 2 + y) + (cub->mini_w / 2 + x)] = 0x00FF00;
	}
}

void	mini_bisector(t_cub *cub)
{
	mini_dda_line((int)(cub->mini_w / 2 + cub->p.dem_x * 2.5), \
		(int)(cub->mini_h / 2 + cub->p.dem_y * 2.5), cub);
}

static void	draw_minisq(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;
	int	imax;
	int	jmax;

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

void	sqrs_minimap(t_cub *cub, int p_i, int p_j)
{
	int	i;
	int	j;
	int	flag_i;
	int	flag_j;

	i = -1;
	j = -1;
	flag_i = 0;
	flag_j = 0;
	while (++j < 9)
	{
		i = -1;
		while (++i < 9)
		{
			flag_i = p_i - (4 - i);
			flag_j = p_j - (4 - j);
			if (flag_i < 0 || flag_i >= cub->row \
				|| flag_j < 0 || flag_j >= cub->col)
			{
			}
			else if (cub->par.map[flag_j][flag_i] != '1')
				draw_minisq(cub, (i), (j), 0xF8A95F);
			else if (cub->par.map[flag_j][flag_i] == '1')
				draw_minisq(cub, (i), (j), 0xb2a562);
		}
	}
}

void	draw_minimap(t_cub *cub)
{
	int	p_j;
	int	p_i;

	p_j = (int)((cub->p.y) / 64);
	p_i = (int)((cub->p.x) / 64);
	mini_bg(cub);
	sqrs_minimap(cub, p_i, p_j);
	player_minimap(cub);
	mini_bisector(cub);
}
